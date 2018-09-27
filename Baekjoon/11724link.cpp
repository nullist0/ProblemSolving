#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

vector<vector<int> > nodes(1001);
int cache[1001];

void bfs(int s){
	queue<int> q;

	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();

		cache[x] = 1;

		for(int i = 0; i < (int)nodes[x].size(); i++){
			if(cache[nodes[x][i]] != 1)
				q.push(nodes[x][i]);
		}
	}
}

int main(){
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int s, e;
		scanf("%d %d", &s, &e);

		nodes[s].push_back(e);
		nodes[e].push_back(s);
	}

	int res = 0;
	for(int i = 1; i <= n; i++){
		if(cache[i] == 0){
			bfs(i);
			res++;
		}
	}
	printf("%d\n", res);
}