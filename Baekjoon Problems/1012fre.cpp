#include <cstdio>
#include <queue>

using namespace std;

int m, n;
int mat[51][51];
int cache[51][51];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int y, int x, int tc){
	int count = 0, xx, yy;
	queue<pair<int, int> > q;

	q.push(make_pair(y, x));
	cache[y][x] = tc;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;

		q.pop();

		for(int i = 0; i < 4; i++){
			yy = y + dir[i][0];
			xx = x + dir[i][1];
			
			if(xx < 0 || xx >= m || yy < 0 || yy >=n) continue;
			if(cache[yy][xx] == tc) continue;

			if(mat[yy][xx] == tc){
				cache[yy][xx] = tc;
				q.push(make_pair(yy, xx));
			}
		}
	}
}

int main(void)
{
	int y, x, c, t;
	int count;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		count = 0;
		scanf("%d %d %d", &m, &n, &c);

		for(int j = 0; j < c; j++){
			scanf("%d %d", &x, &y);
			mat[y][x] = i;
		}

		for(int y = 0; y < n; y++){
			for(int x = 0; x < m; x++){
				if(mat[y][x] == i && cache[y][x] != i){
					bfs(y, x, i);
					count++;
				}
			}
		}

		printf("%d\n", count);
	}
}