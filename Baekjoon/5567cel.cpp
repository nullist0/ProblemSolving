#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > tree(501);
int cache[501];

int bfs(){
	queue<pair<int, int> > q;
	int cnt = -1;

	q.push(make_pair(1, 0));
	cache[1] = 1;
	while(!q.empty()){
		int x = q.front().first;
		int c = q.front().second;

		//printf("(%d %d)", x, c);
		q.pop();
		
		if(c > 2) continue;

		cnt++;

		for(int i = 0; i < tree[x].size(); i++){
			if(cache[tree[x][i]] == 0)
			{
				q.push(make_pair(tree[x][i], c+1));
				cache[tree[x][i]] = 1;
			}
		}
	}

	//printf("\n");
	return cnt;
}

int main(void)
{
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	printf("%d\n", bfs());

	return 0;
}
