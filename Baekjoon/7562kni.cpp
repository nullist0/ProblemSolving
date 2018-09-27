#include <cstdio>
#include <queue>

using namespace std;

int n = 0;
int sx, sy, ex, ey;
int mat[301][301];

int mov[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1},
				{1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

int bfs(int i){
	int x, y, c, xx, yy;
	queue<pair<int, pair<int, int> > > q;

	q.push(make_pair(0, make_pair(sy, sx)));
	mat[sy][sx] = i;

	while(!q.empty()){
		c = q.front().first;
		y = q.front().second.first;
		x = q.front().second.second;

		if(x == ex && y == ey) return c;

		q.pop();
		//printf("%d %d\n", x, y);

		for(int j = 0; j < 8; j++){
			xx = x + mov[j][0]; yy = y + mov[j][1];

			if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			if(mat[yy][xx] == i) continue;
			mat[yy][xx] = i;
			q.push(make_pair(c+1, make_pair(yy, xx)));
		}
	}

	return 0;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for(int i = 0; i < tc; i++){
		scanf("%d", &n);
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", bfs(i+1));
	}

	return 0;
}