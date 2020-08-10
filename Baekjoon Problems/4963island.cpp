#include <cstdio>

int matrix[51][51];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int w = 1, h = 1;

void dfs(int x, int y){
	if((y < 0 || y >= h) || (x < 0 || x >= w))
		return;
	if(matrix[y][x] == 1){
		matrix[y][x] = 0;
		for(int i = 0; i < 8; i++){
			dfs(x + dir[i][0], y + dir[i][1]);
		}
	}
}

int main(){

	int count = 0;

	scanf("%d %d", &w, &h);

	while(w != 0 || h != 0){

		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				scanf("%d", &matrix[y][x]);
			}
		}


		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				if(matrix[y][x] == 1){
					dfs(x, y);
					count++;
				}
			}
		}

		printf("%d\n", count);

		count = 0;
		scanf("%d %d", &w, &h);
	}

	return 0;
}