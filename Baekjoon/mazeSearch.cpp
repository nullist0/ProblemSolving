#include <cstdio>
#include <queue>

using namespace std;

int n = 0, m = 0;
int matrix[101][101];

int dir[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};

int bfs(){
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	matrix[0][0] = 0;

	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int yy = y + dir[i][0], xx = x + dir[i][1];

			if(yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
			if(matrix[yy][xx] == 1){
				q.push(make_pair(yy,xx));
				matrix[yy][xx] = matrix[y][x] + 1;
			}
		}
	}

	return matrix[n-1][m-1]+1;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &matrix[i][j]);
		}
	}

	printf("%d\n", bfs());
}