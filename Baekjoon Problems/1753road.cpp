#include <cstdio>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

vector<vector<pair<int, int> > > edge(20001);
int v, e, s;

vector<int> dijkstra(int s){
	priority_queue<pair<int, int>,
			vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, s));

	vector<int> dist(v+1, INF);
	dist[s] = 0;

	while(!q.empty()){
		int cost = q.top().first, cur = q.top().second;
		q.pop();

		for(int i = 0; i < (int)edge[cur].size(); i++){
			int dest = edge[cur][i].first, nextCost = edge[cur][i].second;
			if(dist[dest] > cost + nextCost){
				dist[dest] = cost + nextCost;
				q.push(make_pair(dist[dest], dest));
			}
		}
	}

	return dist;
}

int main(){
	scanf("%d %d", &v, &e);
	scanf("%d", &s);

	for(int i = 0; i < e; i++){
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		edge[u].push_back(make_pair(v, w));
	}

	vector<int> dist = dijkstra(s);

	for(int i = 1; i <= v; i++){
		if(dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}