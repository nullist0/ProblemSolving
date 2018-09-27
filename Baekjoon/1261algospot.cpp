#include <cstdio>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

int w, h;
int mat[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int> > dijkstra(){
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

	vector<int> row(w, INF);
	vector<vector<int> > dist(h, row);

	dist[0][0] = 0;
	pq.push(make_pair(dist[0][0], make_pair(0, 0)));

	while(!pq.empty()){
		int c = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for(int i = 0; i < 4; i++){
			int yy = y + dir[i][0], xx = x + dir[i][1];
			if(yy < 0 || yy >= h || xx < 0 || xx >= w) continue;

			int cc = c + mat[yy][xx];

			if(dist[yy][xx] > cc){
				dist[yy][xx] = cc;
				pq.push(make_pair(dist[yy][xx], make_pair(yy, xx)));
			}
		}
	}

	return dist;
}

int main(){
	scanf("%d %d", &w, &h);

	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			scanf("%1d", &mat[y][x]);
		}
	}

	vector<vector<int> > d = dijkstra();


	// printf("---------\n");
	// for(int y = 0; y < h; y++){
	// 	for(int x = 0; x < w; x++){
	// 		printf("%1d", d[y][x]);
	// 	}
	// 	printf("\n");
	// }
	// printf("---------\n");

	printf("%d\n", d[h-1][w-1]);
}