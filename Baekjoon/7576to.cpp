#include <cstdio>
#include <queue>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int m, n;
int tomato = 0;
int mat[1001][1001];
int cache[1001][1001];

int bfs(){
	int time = 0;

	queue<pair<int, pair<int, int> > > q;

	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			if(mat[y][x] == 1){
				q.push(make_pair(0, make_pair(y, x)));
				cache[y][x] = 1;
			}
		}
	}

	while(!q.empty()){
		time = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int yy = y + dir[i][0];
			int xx = x + dir[i][1];

			if(yy >= n || yy < 0) continue;
			if(xx >= m || xx < 0) continue;

			if(cache[yy][xx] == 0 && mat[yy][xx] == 0){
				q.push(make_pair(time+1, make_pair(yy, xx)));
				mat[yy][xx] = 1;
				cache[yy][xx] = 1;
				tomato--;
			}
		}
	}

	return time;
}

int main(void){
	int ret = 0;

	scanf("%d %d", &m, &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &mat[i][j]);
			if(mat[i][j] == 0)
				tomato++;
		}
	}

	if(tomato == 0)
		printf("0\n");
	else{
		ret = bfs();

		if(tomato == 0)
			printf("%d\n", ret);
		else
			printf("-1\n");
	}

	return 0;
}