#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 99999999999

using namespace std;

vector<vector<pair<int, int> > > edges(200001);
int n, e;

vector<long> dijkstra(long s){
	priority_queue<pair<long, int>, vector<pair<long, int> >, greater<pair<long, int> > > pq;
	pq.push(make_pair(0, s));

	vector<long> dist(n+1, INF);
	dist[s] = 0;

	while(!pq.empty()){
		int cur = pq.top().second; long cost = pq.top().first;
		pq.pop();

		for(long i = 0; i < edges[cur].size(); i++){
			long next = edges[cur][i].first, nextCost = edges[cur][i].second;
			if(dist[next] > cost + nextCost){
				dist[next] = cost + nextCost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	return dist;
}

int main(){
	scanf("%d %d", &n, &e);

	for(int i = 0; i < e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	int t1, t2;
	scanf("%d %d", &t1, &t2);

	vector<long> f = dijkstra(1);
	long res = min(f[t1] + dijkstra(t1)[t2] + dijkstra(t2)[n],
					f[t2] + dijkstra(t2)[t1] + dijkstra(t1)[n]);
	if(res >= INF)
		printf("-1\n");
	else
		printf("%ld\n", res);
}