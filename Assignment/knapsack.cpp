#include <cstdio>
#include <algorithm>
#include <queue>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 30
#define RAND_MAX_PROFIT 100
#define RAND_MAX_WEIGHT 10

using namespace std;

typedef struct node{
	int index;
	int profit;
	int weight;
} node;

typedef struct boundnode{
	int index;
	int profit;
	int weight;
	double bound;
} bnode;

// int maxprofit = -1;
// int n_nodes = 0;

// int p[N] = {40, 30, 50, 10};
// int w[N] = {2, 5, 10, 5};

class Knapsack{
	protected:
		int W;
		int N, maxprofit = -1, n_nodes = 0;
		int p[MAX_ITEMS], w[MAX_ITEMS];
		double getbound(int,int,int);
		void init();
		void depth_first_search(int, int, int);
		void breadth_first_search();
		void best_first_search();
	public:
		Knapsack(int, int);
		void run();
		void setting();
		void setting(int*, int*);
};

class MonteCarlo : public Knapsack{
	private:
		int T;
		bool promising(node);
		int subestimate();
	public:
		MonteCarlo(int, int, int);
		void estimate();
};

Knapsack::Knapsack(int w, int n){
	srand(time(NULL));
	N = n;
	W = w;
}

double Knapsack::getbound(int i, int profit, int weight){
	int totweight = weight;
	double bound = profit;
	int k;

	for(k = i+1; k < N; k++){
		totweight += w[k];
		bound += p[k];

		if(totweight > W) {
			totweight -= w[k];
			bound -= p[k];
			
			bound += (W - totweight) * (double)p[k]/w[k];
			break;
		}
	}

	return bound;
}

void Knapsack::depth_first_search(int index, int profit, int weight){
	n_nodes++;

	if(weight > W) return;

	if(profit > maxprofit)
		maxprofit = profit;

	double bound = getbound(index, profit, weight);
	//printf("%d %d %d %.2lf\n", index, profit, weight, bound);
	if(maxprofit < bound){
		index++;
		depth_first_search(index, profit + p[index], weight + w[index]);
		depth_first_search(index, profit, weight);
	}
}

void Knapsack::breadth_first_search(){
	queue<node> q;
	node n = {-1, 0, 0};
	q.push(n);

	while(!q.empty()){
		n = q.front();
		int index = n.index;
		int weight = n.weight;
		int profit = n.profit;

		n_nodes++;
		q.pop();

		if(weight > W) continue;

		if(profit > maxprofit)
			maxprofit = profit;

		double bound = getbound(index, profit, weight);
		//printf("%d %d %d %.0lf\n", index, profit, weight, bound);
		if(maxprofit < bound){
			index++;
			q.push({index, profit + p[index], weight + w[index]});
			q.push({index, profit, weight});
		}
	}
}

class Compare
{
public:
    bool operator() (bnode b1, bnode b2)
    {
        return b1.bound < b2.bound;
    }
};

void Knapsack::best_first_search(){
	priority_queue<bnode, vector<bnode>, Compare> q;
	bnode n = {-1, 0, 0, getbound(0, 0, 0)};
	q.push(n);

	while(!q.empty()){
		int index, profit, weight;
		double bound;

		n = q.top();
		
		n_nodes++;
		
		q.pop();

		if(n.bound > maxprofit){
			index = n.index + 1;

			profit = n.profit + p[index];
			weight = n.weight + w[index];

			if(index < N && weight <= W && profit > maxprofit)
				maxprofit = profit;

			bound = getbound(index, profit, weight);
			if(index < N && bound > maxprofit)
				q.push({index, profit, weight, bound});

			profit = n.profit;
			weight = n.weight;
			bound = getbound(index, profit, weight);
			
			if(index < N && bound > maxprofit)
				q.push({index, profit, weight, bound});
		}
	}
}

void Knapsack::init(){
	maxprofit = -1;
	n_nodes = 0;
}

void Knapsack::setting(int *pp, int *ww){
	printf("W : %d\n", W);
	for(int i = 0; i < N; i++){
		p[i] = pp[i];
		w[i] = ww[i];
		printf("I%d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
	}
}

void Knapsack::setting(){
	vector<pair<double, pair<int, int> > > v;
	//srand(time(NULL));
	for(int i = 0; i < N; i++){
		int pp = (rand() % RAND_MAX_PROFIT) * 10 + 10;
		int ww = (rand() % RAND_MAX_WEIGHT) + 1;
		v.push_back(make_pair(pp/ww, make_pair(pp, ww)));
	}

	sort(v.begin(), v.end(), greater<pair<double, pair<int, int> > >());

	//printf("W : %d\n", W);
	for(int i = 0; i < N; i++){
		p[i] = v[i].second.first;
		w[i] = v[i].second.second;
		//printf("I%3d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
	}
}

void Knapsack::run(){
	init();
	depth_first_search(-1, 0, 0);
	printf("depth first search\nmaxprofit: %d, nodes : %d\n", maxprofit, n_nodes);	

	init();
	breadth_first_search();
	printf("breadth first search\nmaxprofit: %d, nodes : %d\n", maxprofit, n_nodes);

	init();
	best_first_search();
	printf("best first search\nmaxprofit: %d, nodes : %d\n", maxprofit, n_nodes);	
}

MonteCarlo::MonteCarlo(int t, int w, int n):
	T(t), Knapsack(w, n)
{
}

bool MonteCarlo::promising(node nd){
	return getbound(nd.index, nd.profit, nd.weight) > maxprofit && nd.weight < W;
}

int MonteCarlo::subestimate(){
	node v = {-1, 0, 0};
	int i, m, mprod, t, r, numnodes, prom_children = 0;
	int profit = 0, weight = 0;

	numnodes = 1;
	m = 1;
	mprod = 1;
	while(m != 0 && i < N){
		mprod *= m;
		numnodes += mprod * 2;
		i = v.index + 1;
		m = 0;

		prom_children = 0;
		for(int j = 0; j < 2; j++){
			profit = v.profit + p[i] * j;
			weight = v.weight + w[i] * j;
			if(promising({i, profit, weight})){
				m++;
				prom_children += (j+1);
				maxprofit = max(maxprofit, profit);
			}
		}

		if(m != 0){
			if(prom_children == 1){
				v = {i, v.profit, v.weight};
			}else if(prom_children == 2){
				v = {i, v.profit + p[i], v.weight + w[i]};
			}else{
				r = rand() % 2;
				v = {i, v.profit + p[i] * r, v.weight + w[i]* r};
			}
		}
	}
	return numnodes;
}

void MonteCarlo::estimate(){
	long long sum_test = 0, cache;
	for(int i = 0; i < T; i++){
		setting();
		cache = subestimate();
		sum_test += cache;
	}
	printf("Avg NUM : %.2lf\n", (double)sum_test/T);
}

int main(void){
	int w = 30;
	{
		Knapsack ex(16, 4);
		int pp[4] = {40, 30, 50, 10};
		int ww[4] = {2, 5, 10, 5};
		ex.setting(pp, ww);
		ex.run();
	}

	{
		Knapsack ex(17, 5);
		int pp[5] = {20, 30, 35, 12, 3};
		int ww[5] = {2, 5, 7, 3, 1};
		ex.setting(pp, ww);
		ex.run();
	}
	
	{
		Knapsack test(w, 10);
		test.setting();
		test.run();
	}

	{
		MonteCarlo mc(100, 10, MAX_ITEMS);
		mc.estimate();
	}
	return 0;
}