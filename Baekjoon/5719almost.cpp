#include <vector>
#include <queue>
#include <cstdio>

#define INF 999999

using namespace std;

int n, m;

vector<vector<pair<int, int> > > edges(10001);

// vector<priority_queue<int, vector<int>, greater<int> > > dijkstra(int s){
// 	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
// 	priority_queue<int, vector<int>, greater<int> > q;
// 	q.push(INF);
// 	vector<priority_queue<int, vector<int>, greater<int> > > dist(n, q);

// 	dist[s].push(0);
// 	pq.push(make_pair(dist[s].top(), s));

// 	while(!pq.empty()){
// 		int cost = pq.top().first, cur = pq.top().second;
// 		pq.pop();

// 		printf("Current %d %d\n", cost, cur);

// 		for(int i = 0; i < edges[cur].size(); i++){
// 			int next = edges[cur][i].first, nextCost = cost + edges[cur][i].second;

// 			printf("Go %d %d\n", nextCost, next);

// 			if(dist[next].top() > nextCost){
// 				dist[next].push(nextCost);
// 				pq.push(make_pair(dist[next].top(), next));
// 			}
// 		}
// 	}

// 	return dist;
// }

// int cache[10001];
// int cnt = 1;

// vector<vector<int> > dijkstra(int s, int e){
// 	priority_queue<int, vector<int>, greater<int> > pq;
	
// 	vector<int> empty;
// 	vector<vector<int> > dist(n, empty);

// 	dist[s].push_back(0);
// 	pq.push(s);

// 	while(!pq.empty()){
// 		int cur = pq.top();
// 		pq.pop();

// 		if(cur == e || cache[cur] == cnt)
// 			continue;

// 		cache[cur] = cnt;

// 		// printf("Current %d %d\n", cost, cur);

// 		for(int i = 0; i < edges[cur].size(); i++){
// 			int next = edges[cur][i].first;
// 			int nextCost = edges[cur][i].second;

// 			// printf("Go %d %d\n", nextCost, next);

// 			for(int i = 0; i < dist[cur].size(); i++){
// 				dist[next].push_back(dist[cur][i] + nextCost);
// 			}
// 			pq.push(next);
// 		}
// 	}

// 	return dist;
// }

// int count = 0;
// vector<int> dijkstra(int s, int e){
// 	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
// 	vector<int> dist(n, INF);
// 	vector<vector<int> > path(n);

// 	dist[s] = 0;
// 	pq.push(make_pair(dist[s], s));

// 	path[count] = s;

// 	while(!pq.empty()){
// 		int cur = pq.top().second;
// 		int cost = pq.top().first;
// 		pq.pop();

// 		for(int i = 0; i < edges[cur].size(); i++){
// 			int next = edges[cur][i].first;
// 			int nextCost = cost + edges[cur][i].second;

// 			if(dist[next] > nextCost){
// 				dist[next] = nextCost;
// 				pq.push(make_pair(dist[next], next));
// 			}
// 		}
// 	}

// 	return dist;
// }

int count = 0;
vector<int> dijkstra(int s, int e){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	vector<int> dist(n, INF);
	vector<int> path;

	dist[s] = 0;
	pq.push(make_pair(dist[s], s));

	while(!pq.empty()){
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for(int i = 0; i < edges[cur].size(); i++){
			int next = edges[cur][i].first;
			int nextCost = cost + edges[cur][i].second;

			if(dist[next] > nextCost){
				dist[next] = nextCost;
				pq.push(make_pair(dist[next], next));
				path.push_back(next);
			}
		}
	}

	for(int i = 0; i < path.size(); i++){
		printf("%d ", path[i]);
	}
	printf("\n");

	return dist;
}

int main(){
	int start, end;
	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0){
		scanf("%d %d", &start, &end);
		
		for(int i = 0; i < n; i++){
			edges[i].clear();
		}

		for(int i = 0; i < m; i++){
			int s, d, u;
			scanf("%d %d %d", &s, &d, &u);
			edges[s].push_back(make_pair(d, u));
		}

		// if(edges[start].size() != 1 && edges[end].size() != 1){
			vector<int> res = dijkstra(start, end);
			printf("%d\n", res[end]);
		// }else{
			// printf("-1\n");
		// }

		scanf("%d %d", &n, &m);
	}
}