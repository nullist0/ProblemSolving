#include <cstdio>
#include <queue>

using namespace std;

int matrix[501][501];
int dir[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};

int N, M;

int max(int x, int y){
	if(x >= y)
		return x;
	else
		return y;
}

int bfs(int sy, int sx){
	queue<pair<int, int > > q;
	int res = 0, y, yy, x, xx;
	
	q.push(make_pair(sy, sx));
	matrix[sy][sx] = 0;
	res++;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			yy = y + dir[i][0];
			xx = x + dir[i][1];

			//if exception error control is none
			//insert printf in line 60 - 61 no error?!
			if(yy < 0 || yy >= N || xx < 0 || xx >= M) continue;
			if(matrix[yy][xx] == 1){
				q.push(make_pair(yy, xx));
				matrix[yy][xx] = 0;
				res++;
			}
		}
	}

	return res;
}

int main(){
	int res = 0, pN = 0;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(matrix[i][j] == 1){
				pN++;
				res = max(res, bfs(i, j));
			}
		}
	}
	printf("%d\n%d\n", pN, res);
}