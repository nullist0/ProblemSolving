#include <cstdio>
#include <vector>

int N;
char stars[6562][6562];

void print(int x, int y, int len){
	int i, j;
	if(len == 1){
		stars[y][x] = '*';
	}
	else{
		for(i = 0; i < 3; i < i++){
			for(j = 0; j < 3; j++){
				if(i == 1 && j == 1) continue;
				print(x + i * len/3, y + j * len/3, len/3);	
			}
		}
	}
}

int main(void){
	int i, j;
	scanf("%d", &N);

	for(i = 0; i < N; i ++)
		for(j = 0; j < N; j ++)
			stars[i][j] = ' ';

	print(0,0,N);

	for(i = 0; i < N; i++){
		stars[i][N] = '\0';
		printf("%s\n", stars[i]);
	}

	return 0;
}