#include <cstdio>
#include <algorithm>
#include <queue>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 256
#define RAND_MAX_PROFIT 1000
#define RAND_MAX_WEIGHT 50

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

class Knapsack{
	protected:
		int W;
		int N, maxprofit = -1, n_nodes = 0;
		int p[MAX_ITEMS], w[MAX_ITEMS];
		double getbound(int,int,int);
		void init();
		void depth_first_search(int, int, int);
		void breadth_first_search();
		int best_first_search();
	public:
		Knapsack();
		void run();
		void runWithoutPrint(int*);
		void print();
		void setting(int, int, int, int);
		void setting(int, int, int*, int*);
};

class MonteCarlo : public Knapsack{
	private:
		bool promising(node);
		bool promising(bnode nd);
		int subestimate();
	public:
		MonteCarlo();
		double estimate(int, int, int);
		double bestEstimate(int, int, int);
};

Knapsack::Knapsack(){
	srand(time(NULL));
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

int Knapsack::best_first_search(){
	priority_queue<bnode, vector<bnode>, Compare> q;
	bnode n = {-1, 0, 0, getbound(-1, 0, 0)};
	q.push(n);

	while(!q.empty()){
		int index, profit, weight;
		double bound;

		n = q.top();
		
		n_nodes++;
		
		q.pop();

		if(n.weight > W) continue;

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
	return n_nodes;
}

void Knapsack::init(){
	maxprofit = -1;
	n_nodes = 0;
}

void Knapsack::setting(int mw, int n, int *pp, int *ww){
	N = n;
	W = mw;
	printf("W : %d\n", W);
	for(int i = 0; i < N; i++){
		p[i] = pp[i];
		w[i] = ww[i];
		printf("I%d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
	}
}

void Knapsack::setting(int n, int maxW, int minP, int maxP){
	N = n;
	W = maxW;
	vector<pair<double, pair<int, int> > > v;
	//srand(time(NULL));
	for(int i = 0; i < N; i++){
		int pp = (rand() % (maxP - minP)) + minP;
		int ww = (rand() % maxW) + 1;
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

void Knapsack::runWithoutPrint(int* res){
	init();
	depth_first_search(-1, 0, 0);
	res[0] = n_nodes;

	init();
	breadth_first_search();
	res[1] = n_nodes;
	
	init();
	best_first_search();
	res[2] = n_nodes;
}

void Knapsack::print(){
	printf("W : %d\n", W);
	for(int i = 0; i < N; i++)
		printf("I%3d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
}

MonteCarlo::MonteCarlo():
	Knapsack()
{
}

bool MonteCarlo::promising(node nd){
	return getbound(nd.index, nd.profit, nd.weight) > maxprofit && nd.weight < W;
}

bool MonteCarlo::promising(bnode nd){
	return nd.bound > maxprofit && nd.weight < W;
}

int MonteCarlo::subestimate(){
	bnode v = {-1, 0, 0, getbound(-1, 0, 0)};
	int i, m, mprod, t, r, numnodes, prom_children = 0;
	int profit = 0, weight = 0;

	double nbound[2], bound;

	numnodes = 1;
	m = 1;
	mprod = 1;
	while(m != 0 && i < N){
		mprod *= m;
		numnodes += mprod * 2;
		i = v.index + 1;
		m = 0;

		prom_children = 0;

		profit = v.profit;
		weight = v.weight;
		bound = v.bound;

		if(weight <= W)
			maxprofit = max(maxprofit, profit);
		
		for(int j = 0; j < 2; j++){
			profit = v.profit + p[i] * j;
			weight = v.weight + w[i] * j;
			nbound[j] = getbound(i, profit, weight);
			if(promising({i, profit, weight, nbound[j]})){
				m++;
				prom_children += (j+1);
			}
		}

		if(m != 0){
			if(prom_children == 1){
				profit = v.profit;
				weight = v.weight;
				v = {i, profit, weight, nbound[0]};
			}else if(prom_children == 2){
				profit = v.profit + p[i];
				weight = v.weight + w[i];
				v = {i, profit, weight, nbound[1]};
			}else{
				// r = rand() % 2;
				// profit = v.profit + p[i] * r;
				// weight = v.weight + w[i] * r;
				// v = {i, profit, weight, nbound[r]};
				if(nbound[0] < nbound[1]){
					profit = v.profit + p[i];
					weight = v.weight + w[i];

					v = {i, profit, weight, nbound[1]};
				}
				else{
					profit = v.profit;
					weight = v.weight;
					
					v = {i, profit, weight, nbound[0]};
				}
			}
		}
	}
	return numnodes;
}

double MonteCarlo::estimate(int T, int N, int maxW){
	long long sum_test = 0, cache;
	int randW = 0;

	for(int i = 0; i < T; i++){
		init();
		randW = rand() % maxW + 1;
		setting(N, randW, randW, 100*randW);
		cache = subestimate();
		sum_test += cache;
	}
	printf("Avg NUM : %.2lf\n", (double)sum_test/T);
	return (double)sum_test / T;
}

double MonteCarlo::bestEstimate(int T, int N, int W){
	long long sum_test = 0, cache;
	int randW = 0;

	for(int i = 0; i < T; i++){
		init();
		randW = rand() % W + 1;
		setting(N, randW, randW, 100*randW);
		cache = best_first_search();
		sum_test += cache;
	}
	printf("Avg NUM : %.2lf\n", (double)sum_test/T);
	return (double)sum_test / T;
}

int main(void){
	
	//int w = 30;

/*// 1, 2, 3, 4
	Knapsack ex;
	{
		int pp[4] = {40, 30, 50, 10};
		int ww[4] = {2, 5, 10, 5};
		ex.setting(16, 4, pp, ww);
		ex.run();
	}

	{
		int pp[5] = {20, 30, 35, 12, 3};
		int ww[5] = {2, 5, 7, 3, 1};
		ex.setting(13, 5, pp, ww);
		ex.run();
	}
*/

/*
	Knapsack k;
	int res[3];
	int distribution[3][2] = {{0,0}, {0,0}, {0,0}};
	int n = 10, t = 1000000, w = 30, i = 0;
	while(t--){
		k.setting(n, w, w, 100 * w);
		k.runWithoutPrint(res);
		//dfs  : res[0]
		//bfs  : res[1]
		//bbfs : res[2]
		distribution[0][res[1] < res[0]]++;
		distribution[1][res[1] < res[2]]++;
		distribution[2][res[0] < res[2]]++;
		if(res[0] < res[2]){
			k.print();
			k.run();
			printf("\n");
			i++;
		}
	}

	printf("W : %d, N : %d\n", w, n);
	char *s[] = {"dfs < bfs", "bfs < bbfs", "dfs < bbfs"};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			printf("%c%s : %d\n", j == 0 ? '!' : ' ', s[i], distribution[i][j]);
		}
	}
*/

	int t = 10000, w = 100, n = 30;
	MonteCarlo m;
	printf("Estimation : %.2lf\n", m.estimate(t, n, w));
	printf("Best Estimation : %.2lf\n", m.bestEstimate(t, n, w));	
	return 0;
}
