#include <cstdio>
#include <algorithm>

using namespace std;

int mat[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int area[101];

int m, n, k;

int a = 0;

void dfs(int y, int x){
	if((y < 0 || y >= m) || (x < 0 || x >= n))
		return;
	if(mat[y][x] == 0){
		mat[y][x] = 1;
		a++;
		for(int i = 0; i < 4; i++){
			dfs(y + dir[i][1], x + dir[i][0]);
		}
	}
	return;
}

int main(){
	int x0, x1, y0, y1;
	int count = 0;

	scanf("%d %d %d", &m, &n, &k);

	for(int i = 0; i < k; i++){
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		for(int j = y0; j < y1; j++){
			for(int l = x0; l < x1; l++){
				mat[j][l] = 1;
			}
		}
	}


	// for(int j = 0; j < m; j++){
	// 	for(int l = 0; l < n; l++){
	// 		printf("%d ", mat[j][l]);
	// 	}
	// 	printf("\n");
	// }

	for(int j = 0; j < m; j++){
		for(int l = 0; l < n; l++){
			if(mat[j][l] == 0){
				a = 0;
				dfs(j, l);
				area[count] = a;
				count++;
			}
		}
	}

	sort(&area[0], &area[count]);

	printf("%d\n", count);
	for(int i = 0; i < count; i++){
		printf("%d ", area[i]);
	}
	printf("\n");
}