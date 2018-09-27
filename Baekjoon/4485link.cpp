#include <vector>
#include <queue>
#include <cstdio>

#define INF 9999999

using namespace std;

int mat[126][126];
int n = 0;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

vector<vector<int> > dijkstra(){
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

	vector<int> d(n, INF);
	vector<vector<int> > dist(n, d);

	dist[0][0] = mat[0][0];
	pq.push(make_pair(dist[0][0], make_pair(0, 0)));

	while(!pq.empty()){
		int y,x,c;
		c = pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;

		mat[y][x] = 0;

		pq.pop();

		for(int i = 0; i < 4; i++){
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if(yy < 0 || yy >= n || xx < 0 || xx >= n) continue;

			int cc = mat[yy][xx];
			if(dist[yy][xx] > c + cc){
				dist[yy][xx] = c + cc;
				pq.push(make_pair(dist[yy][xx], make_pair(yy, xx)));
			}
		}
	}
	
	return dist;
}

int main(){
	scanf("%d", &n);

	for(int i = 1; n != 0; i++){

		for(int y = 0; y < n; y++){
			for(int x = 0; x < n; x++){
				scanf("%d", &mat[y][x]);
			}
		}

		vector<vector<int> > r = dijkstra();
		printf("Problem %d: %d\n", i, r[n-1][n-1]);

		scanf("%d", &n);
	}
}