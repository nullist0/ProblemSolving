#include <cstdio>
#include <queue>

using namespace std;

char mat[101][101];
int n = 0, m = 0;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int y, int x){
	if(y < 0 || y >= n || x < 0 || x >= m) return;
	if(mat[y][x] == '#')
		mat[y][x] = '.';
	else
		return;

	for(int i = 0; i < 4; i++){
		int yy = y + dir[i][0], xx = x + dir[i][1];
		dfs(yy, xx);
	}
}

int main(){
	int t = 0;

	scanf("%d", &t);

	for(int i = 0; i < t; i++){

		scanf("%d %d", &n, &m);

		for(int y = 0; y < n; y++){
			for(int x = 0; x < m; x++){
				scanf(" %c", &mat[y][x]);
			}
		}

		int count = 0;
		for(int y = 0; y < n; y++){
			for(int x = 0; x < m; x++){
				if(mat[y][x] == '#'){
					count++;
					dfs(y, x);
				}
			}
		}

		printf("%d\n", count);
	}
}