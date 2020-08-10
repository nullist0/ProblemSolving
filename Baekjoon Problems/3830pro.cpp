#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n = 0, cnt = 1;
int id[100001];
vector<vector<pair<int, int> > > node(100001);

// int dfs(int s, int e, int res){
// 	if(s == e)
// 		return res;
// 	for(int i = 0; i < node[s].size(); i++){
// 		if(node[s][i].second != 0 && id[node[s][i].first] != cnt){
// 			id[node[s][i].first] = cnt;
// 			dfs(node[s][i].first, e, res + node[s][i].second);
// 		}
// 	}
// }

// 1
// -1
// UNKNOWN
// 100
// 200
// -50

int bfs(int s, int e){
	int res = 0;
	id[s] = cnt;

	queue<pair<int, int> > q;
	q.push(make_pair(s, 0));

	while(!q.empty()){
		int x = q.front().first, cost = q.front().second;
		// printf("%d %d %d\n", s, x, cost);
		q.pop();

		id[x] = cnt;

		if(e == x){
			res = cost;
			break;
		}
		for(int i = 0; i < node[x].size(); i++){
			if(id[node[x][i].first] != cnt)
				q.push(make_pair(node[x][i].first,
						node[x][i].second + cost));
		}
	}
	return res;
}

int main(){
	int m = 0;
	scanf("%d %d", &n, &m);

	while(n != 0 && m != 0){
		for(int i = 0; i < m; i++){
			int a = 0, b = 0, w = 0;
			string s = "";
			cin >> s;
			if(s == "!"){
				scanf("%d %d %d", &a, &b, &w);
				node[b].push_back(make_pair(a, w));
				node[a].push_back(make_pair(b, -w));
			}else if(s == "?"){
				scanf("%d %d", &a, &b);
				int res = bfs(b, a);
				if(res == 0)
					printf("UNKNOWN\n");
				else
					printf("%d\n", res);
				cnt++;
			}
		}

		for(int i = 1; i <= n; i++)
			node[i].clear();

		scanf("%d %d", &n, &m);
	}
}