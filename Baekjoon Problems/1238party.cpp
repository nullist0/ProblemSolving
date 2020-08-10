#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define INF 99999999

using namespace std;

vector<vector<pair<int, int> > > edges(10001);
int n, m, x;

vector<int> dijkstra(int s){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, s));

	vector<int> dist(n+1, INF);
	dist[s] = 0;

	while(!pq.empty()){
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();

		for(int i = 0; i < edges[cur].size(); i++){
			int dest = edges[cur][i].first, destCost = edges[cur][i].second;
			if(dist[dest] > destCost + cost){
				dist[dest] = destCost + cost;
				pq.push(make_pair(dist[dest], dest));
			}
		}
	}

	return dist;
}

int main(){
	scanf("%d %d %d", &n, &m, &x);

	for(int i = 0; i < m; i++){
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);

		edges[s].push_back(make_pair(e, c));
	}

	int res = 0;
	vector<int> come = dijkstra(x);
	for(int i = 1; i <= n; i++){
		vector<int> go = dijkstra(i);
		int cost = go[x] + come[i];
		res = max(res, cost);
	}

	printf("%d\n", res);
}