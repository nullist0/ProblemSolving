#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int cache[10001], node[100001];
vector<vector<int> > graph(10001);

void bfs(int s){
	if(node[s] > 0) return;

	queue<pair<int, int> > q;
	
	q.push(make_pair(s, 1));

	while(!q.empty()){
		int c = q.front().first, n = q.front().second;
		int size = graph[c].size();
		cache[c] = s;

		q.pop();

		for(int i = 0; i < size; i++){
			int next = graph[c][i], nextN = n+1;
			if(node[c] == 0 && node[next] > 0) nextN = n + node[next];
			if(cache[next] == s) continue;

			q.push(make_pair(next, nextN));
		}
		node[c] = n;
	}
}

int main(){
	int n, m, a, b;
	int max, tmp;
	vector<int> mm;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
	}

	for(int i = 1; i <= n; i++){
		bfs(i);
	}

	for(int i = 0; i < n; i++)
		if(max < node[i])
			max = node[i];

	for(int i = 0; i < n; i++)
		if(node[i] == max)
			printf("%d ", i);
	printf("\n");
	return 0;
}