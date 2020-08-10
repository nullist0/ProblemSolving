#include <vector>
#include <queue>
#include <cstdio>

#define INF 999999999

using namespace std;

vector<vector<pair<int, int> > > edges(100001); 
vector<int> dist(1001, INF);

int cache[1001];

void dijkstra(int s){
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while(!pq.empty()){
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for(int i = 0; i < (int)edges[cur].size(); i++){
			int next = edges[cur][i].first, nextCost = edges[cur][i].second;
			if(dist[next] > nextCost + cost){
				dist[next] = nextCost + cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main(){
	int n, m, start, end;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int s, e, c;

		scanf("%d %d %d", &s, &e, &c);

		edges[s].push_back(make_pair(e, c));
	}

	scanf("%d %d", &start, &end);

	dijkstra(start);

	printf("%d\n", dist[end]);
}