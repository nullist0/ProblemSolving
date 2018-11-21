#include <cstdio>
#include <algorithm>
#include <queue>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#define MAX_ITEMS 4096
#define RAND_MAX_PROFIT 1000
#define RAND_MAX_WEIGHT 50

using namespace std;

typedef struct boundnode{
	int index;
	unsigned long long profit;
	unsigned long long weight;
	long double bound;
} bnode;

class Knapsack{
	protected:
		int N;
		unsigned long long W, maxprofit = 0, n_nodes = 0;
		unsigned long long p[MAX_ITEMS], w[MAX_ITEMS];
		long double getbound(long long, unsigned long long, unsigned long long);
	public:
		Knapsack();
		void init();
        void init(int, int);
		void print();
		void setting(int, int, int, int);
		void setting(int, int, unsigned long long*, unsigned long long*);
		void sorting(int, int*, int*);
		unsigned long long best_first_search();
};

class MonteCarlo : public Knapsack{
	private:
		bool promising(bnode nd);
	public:
		MonteCarlo();
		unsigned long long estimate();
		long double estimateInstance(int, int, int);
		long double estimateInstance2(int, int, int);
		long double estimateInstance3(int, int, int);
		// long double estimate(int, int, int);
		long double realBestAverage(int, int, unsigned long long);
		unsigned long long realBestMax(int, int, int);
};

Knapsack::Knapsack(){
	srand(time(NULL));
}

long double Knapsack::getbound(long long i, unsigned long long profit, unsigned long long weight){
	unsigned long long totweight = weight;
	long double bound = profit;
	unsigned long long k;

	n_nodes++;

	// printf("%d %d %d\n", i+1, profit, weight);

	if(weight >= W) return 0;
	for(k = i+1; k < N; k++){
		totweight += w[k];
		bound += p[k];

		if(totweight > W) {
			totweight -= w[k];
			bound -= p[k];
			
			bound += (W - totweight) * (long double)p[k]/w[k];
			break;
		}
	}

	return bound;
}

class Compare
{
public:
    bool operator() (bnode b1, bnode b2)
    {
        if(b1.bound < b2.bound || b1.index < b2.index)
            return true;
        return false;
    }
};

unsigned long long Knapsack::best_first_search(){
	priority_queue<bnode, vector<bnode>, Compare> q;
	bnode n = {-1, 0, 0, getbound(-1, 0, 0)};
	q.push(n);

    long long index;
    unsigned long long profit, weight;
    long double bound;

	while(!q.empty()){

		n = q.top();
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
	return n_nodes;
}

void Knapsack::init(){
	maxprofit = 0;
	n_nodes = 0;
}

void Knapsack::init(int n, int w){
    N = n;
    W = w;
	maxprofit = 0;
	n_nodes = 0;
}

void Knapsack::setting(int mw, int n, unsigned long long *pp, unsigned long long *ww){
	N = n;
	W = mw;

	//printf("W : %d\n", W);
	for(int i = 0; i < N; i++){
		p[i] = pp[i];
		w[i] = ww[i];
		//printf("I%d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
	}
}

void Knapsack::setting(int n, int maxW, int minP, int maxP){
	N = n;
	W = maxW;
	vector<pair<long double, pair<unsigned long long, unsigned long long> > > v;
	//srand(time(NULL));
	for(unsigned long long i = 0; i < N; i++){
		unsigned long long pp = (rand() % (maxP - minP)) + minP;
		unsigned long long ww = (rand() % maxW) + 1;
		v.push_back(make_pair((long double)pp/ww, make_pair(pp, ww)));
	}

	sort(v.begin(), v.end(), greater<pair<long double, pair<unsigned long long, unsigned long long> > >());

	//printf("W : %d\n", W);
	for(unsigned long long i = 0; i < N; i++){
		p[i] = v[i].second.first;
		w[i] = v[i].second.second;
		//printf("I%3d : %d\t %d\t %.2lf\n", i, p[i], w[i], (double)p[i]/w[i]);
	}
}

void Knapsack::print(){
	printf("W : %lld\n", W);
	for(int i = 0; i < N; i++)
		printf("I%3d : %lld\t %lld\t %.2Lf\n", i, p[i], w[i], (long double)p[i]/w[i]);
		// printf("I%3d : %d\t %d\n", i, p[i], w[i]);
}

MonteCarlo::MonteCarlo():
	Knapsack()
{
}

bool MonteCarlo::promising(bnode nd){
	return nd.bound > maxprofit && nd.weight < W;
}

unsigned long long MonteCarlo::estimate(){
    init();
	bnode v = {-1, 0, 0, getbound(-1, 0, 0)}, nv;
    int i, prom_children;
	unsigned long long profit = 0, weight = 0;

	long double nbound[2];

    vector<vector<bnode> > map(N+1);
    vector<bnode> path(N+1);

    //Building a random path.
    i = -1;
    map[0].push_back(v);
    path[0] = v;
	while(map[i+1].size() != 0 && i < N-1){
		i = v.index+1;

		for(int j = 1; j >= 0; j--){
			profit = v.profit + p[i] * j;
			weight = v.weight + w[i] * j;
			
			if(weight <= W && maxprofit < profit)
				maxprofit = profit;
            
            nv = {i, profit, weight, getbound(i, profit, weight)};
			if(promising(nv))
                map[i+1].push_back(nv);
		}

		if(map[i+1].size() != 0){
			if(map[i+1].size() == 1){
				v = map[i+1][0];
                path[i+1] = v;
			}
			else{
				v = map[i+1][rand()%2];
                path[i+1] = v;
			}
		}
	}

    //get the number of promising nodes.
    init();
    int m[N];
    for(int j = 0; j < N; j++)
        m[j] = 0;
	priority_queue<bnode, vector<bnode>, Compare> q;
    q.push(path[0]);
    m[0] = 1;
    while(!q.empty()){
        v = q.top();
        q.pop();

        i = v.index + 1;
        if(v.index == path[i].index && v.profit == path[i].profit && v.weight == path[i].weight){
            if(!promising(v)) continue;
            for(int j = 0; j < map[i+1].size(); j++){
                v = map[i+1][j];
                if(v.weight <= W && maxprofit < v.profit)
                    maxprofit = v.profit;
                if(promising(v)){
                    m[i+1]++;
                    q.push(v);
                }
            }
        }
        else{
            if(v.weight <= W && maxprofit < v.profit)
                maxprofit = v.profit;
        }
    }

    //evaluate numnodes
    unsigned long long numnodes = 1;
    unsigned long long mprod = 1;
    i = 0;
    while(i < N){
        mprod *= m[i];
        numnodes += mprod * 2;
        i++;
    }
	return numnodes;
}

// long double MonteCarlo::estimateInstance(int T, int n, int maxW){
// 	unsigned long long sum = 0;
// 	unsigned long long randW = rand() % maxW + 1;
// 	setting(n, randW, randW, 100*randW);
//     // print();
// 	for(unsigned long long j = 0; j < T; j++){
// 		init();
// 		sum += subestimate();
// 	}
// 	// printf("[%lld]", sum);
// 	return (long double)sum / T;
// }

// long double MonteCarlo::estimate(int T, int n, int maxW){
// 	unsigned long long sum = 0;

// 	for(unsigned long long i = 0; i < T; i++){
// 		init();
// 		sum += estimateInstance(10, n, maxW)/10;
//         // printf("%llu\n", sum);
// 	}
// 	//printf("Avg NUM : %.2Lf\n", sum);
// 	return (long double)sum / T;
// }

long double MonteCarlo::realBestAverage(int T, int n, unsigned long long maxW){
    unsigned long long sum_test = 0, cache, maxb = 0;
    unsigned long long randW = 0;
    
    for(int i = 0; i < T; i++){
        randW = rand() % maxW + 1;
        setting(n, randW, randW, 100*randW);
        init();
        cache = best_first_search();
        sum_test += cache;
    }
    // printf("Average Nodes : %.2Lf\n", (long double)sum_test/T);
    return (long double)sum_test/T;
}

unsigned long long MonteCarlo::realBestMax(int T, int n, int maxW){
	unsigned long long cache, maxb = 0, sum = 0;
	unsigned long long randW = 0;
	
	// for(int j = 0; j < 10; j++){
		for(int i  = 0; i < T; i++){
			randW = rand() % maxW + 1;
            // setting(n, n, pp, ww);
			setting(n, randW, randW, 100*randW);
			init();
			cache = best_first_search();
			if(maxb < cache){
				maxb = cache;
			}
		}
	// 	sum += maxb;
	// }
	// printf("MAX Nodes : %.2Lf\n", (long double)sum / T);
	// printf("MAX Nodes : %lld\n", maxb);
    return maxb;
}

void estimateKnapsack(int t, int n, int w){
    MonteCarlo m;
    unsigned long long sumCache, sumBest = 0;
    long double sumEstimation = 0;
    for(int j = 0; j < t; j++){
        m.init();
        m.setting(n, w, w, 100 * w);
        sumBest += m.best_first_search();
        sumCache = 0;
        for(int i = 0; i < t; i++){
            sumCache += m.estimate()/t;
        }
        sumEstimation += sumCache;
		printf("%.2Lf\n", sumEstimation);
    }
	printf("Testcase : %d, N : %d, W : %d\n", t, n, w);
    printf("BEST : %.2Lf\n", (long double)sumBest/t);
    printf("ESTIMATE : %.2Lf\n", sumEstimation/t);
}

int main(void){
// {
//     Knapsack k;
//     int n = 10, w = 50;
//     k.setting(n, w, w, 100 * w);
//     k.best_first_search();
//     k.printPromisings();
// }

{
	// int t = 100;
    // unsigned long long n = 200;
    // unsigned long long w = 1;
    // unsigned long long cache = 0;
	// unsigned long long lim = 1000;
    // MonteCarlo m;

    // printf("T: %d, N: %llu\n", t, n);
    // w = n;
    // while(w <= 50000){
    //     cache += m.realBestMax(t, n, w);
    //     // if(w % 1000 == 0)
    //     //     printf("W: %llu Data: %llu\n", w, cache);
    //     w+=n;
    // }
    // printf("RESULT : %.2Lf\n", (long double)cache/(w/n));
}

{
	printf("%d\n", sizeof(long long));
    // for(int n = 50; n <= 1000; n+=50)
        estimateKnapsack(500, 1000, 50000);
}

{
	// NO ERROR N MAXIMUM : 1000
	// int t = 100, n = 200, w = 50000;
	// MonteCarlo m;
	// printf("TestCase : %d, N : %d, W : %d\n", t, n, w);
	// printf("Estimation : %.2Lf\n", m.estimate(t, n, w));
	// m.realBestAverage(t, n, w);
}
	return 0;
}
