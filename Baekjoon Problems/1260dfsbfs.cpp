#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > v(1001);

bool chkd[1001];

void dfs(int s){
	printf("%d ", s);

	chkd[s] = 1;

	for(int i = 0; i < v[s].size(); i++){
		if(chkd[v[s][i]] == 0)
			dfs(v[s][i]);
	}
}

bool chkb[1001];

void bfs(int s){
	printf("%d ", s);
	queue<int> q;

	q.push(s);
	chkb[s] = 1;

	while(!q.empty()){
		int ss = q.front(); q.pop();

		if(chkb[ss] == 0)
			printf("%d ",ss);
		chkb[ss] = 1;

		for(int i = 0; i < v[ss].size(); i++){
			if(chkb[v[ss][i]] == 0)
				q.push(v[ss][i]);
		}
	}
}

int main(){

	int n, m, st;

	scanf("%d %d %d", &n, &m, &st);

	for(int i = 0; i < m; i++){
		int s,t;
		scanf("%d %d", &s, &t);

		v[s].push_back(t);
		v[t].push_back(s); 
	}

	for(int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	dfs(st);
	printf("\n");
	bfs(st);
	printf("\n");
}