#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int h, w, n;

int mat[1001][1001];
char testmat[1001][1001];
vector<pair<int, int> > cheese(9);

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// void print(){
// 	printf("----------\n");
// 	for(int y = 0; y < h; y++){
// 		for(int x = 0; x < w; x++){
// 			printf("%d ", mat[y][x]);
// 		}
// 		printf("\n");
// 	}
// 	printf("----------\n");
// }

int bfs(bool flag, int sy, int sx, int ey, int ex){
	queue<pair<int, int> > q;
	int mmat[1001][1001] = {0, };
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			mmat[y][x] = mat[y][x];
		}
	}

	mmat[sy][sx] = 1;

	q.push(make_pair(sy, sx));
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();

		if(y == ey && x == ex)
			return mmat[ey][ex]-1;

		for(int i = 0; i < 4; i++){
			int yy = y + dir[i][0], xx = x + dir[i][1];
			if(yy < 0 || yy >= h || xx < 0 || xx >= w) continue;

			if(mmat[yy][xx] == 0){
				mmat[yy][xx] = mmat[y][x] + 1;
				q.push(make_pair(yy, xx));
			}
		}

		// printf("----------\n");
		// for(int y = 0; y < h; y++){
		// 	for(int x = 0; x < w; x++){
		// 		printf("%d ", mmat[y][x]);
		// 	}
		// 	printf("\n");
		// }
		// printf("----------\n");
	}
}

int main(){
	int sx, sy = 0;
	scanf("%d %d %d", &h, &w, &n);

	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			char t = 0;
			scanf(" %c", &t);
			if('1' <= t && t <= '9'){
				cheese[t - '1'] = make_pair(y, x);
				t = '.';
				mat[y][x] = 0;
			}
			else if(t == 'S'){
				sx = x;
				sy = y;
				mat[y][x] = 0;
			}
			else if(t == '.'){
				mat[y][x] = 0;
			}
			else if(t == 'X'){
				mat[y][x] = 1;
			}
		}
	}

	int res = 0;
	bool flag = false;
	res += bfs(flag, sy, sx, cheese[0].first, cheese[0].second);

	for(int i = 0; i < n-1; i++){
		flag = !flag;
		res += bfs(flag, cheese[i].first, cheese[i].second,
					cheese[i+1].first, cheese[i+1].second);
	}

	printf("%d\n", res);
}