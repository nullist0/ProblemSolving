#include <cstdio>
#include <vector>

int paper[2187][2187];
int ans[3];

void slice(int x, int y, int len){
	int fx = x + len, fy = y + len;
	int i, j, k, l;
	int initial = paper[x][y];
	for(i = x; i < fx; i++){
		for(j = y; j < fy; j++){
			if(paper[i][j] != initial){
				for(k = 0; k < 3; k++)
					for(l = 0; l < 3; l++)
						slice(x + k*len/3, y + l*len/3, len/3);
				return;
			}
		}
	}

	ans[initial + 1]++;
}

int main(void){
	int N, i, j;

	scanf("%d", &N);

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &paper[i][j]);
		}
	}
	slice(0, 0, N);

	for(i = 0; i < 3; i++)
		printf("%d\n", ans[i]);

	return 0;
}