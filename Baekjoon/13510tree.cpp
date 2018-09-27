#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<pair<int, int>, int> > mat;
int n, m;

int bfs(int s, int e)
{
	int u, v, res = 0;
	queue<pair<int, int> > q;

	while(q.empty()){
		for(int i = 0; i < n; i++){
			u = mat[i].first.first;
			v = mat[i].first.second;

			if(u == )
		}
	}
}

int main(void)
{
	int u, v, w;
	int a, b, c;

	//tree
	scanf("%d", &n);
	n--;

	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &u, &v, &w);
		mat.push_back(make_pair(make_pair(u, v), w));
	}

	//query
	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1){
			mat[b].second = c;
		}
		else{

		}
	}

	return 0;
}