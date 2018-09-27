#include <cstdio>
#include <queue>

using namespace std;

int n;
int mat[101][101];
int cache[101][101];

int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int h){
	int count = 0;
	int cy, cx, ny, nx;
	for(int y = 0; y < n; y++){
		for(int x = 0; x < n; x++){
			if(cache[y][x] == h || mat[y][x] <= h) continue;

			count ++;

			queue<pair<int, int> > q;
			q.push(make_pair(y, x));
			cache[y][x] = h;

			while(!q.empty()){
				cy = q.front().first;
				cx = q.front().second;

				q.pop();

				for(int i = 0; i < 4; i++){
					ny = cy + mov[i][0]; nx = cx + mov[i][1];
					if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if(cache[ny][nx] == h || mat[ny][nx] <= h) continue;
					cache[ny][nx] = h;

					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return count;
}

int main(void){
	int max = 1, tmp;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	for(int i = 1; i <= 100; i++){
		tmp = bfs(i);
		if(tmp == 0) break;
		if(tmp > max) max = tmp;
	}

	printf("%d\n", max);
	return 0;
}