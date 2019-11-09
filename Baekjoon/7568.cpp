#include <cstdio>
#include <iostream>

int main(void){
	int p[50][3];
	int N, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d %d", &p[i][0], &p[i][1]);
		p[i][2] = 1;
	}
	for(i = 0; i < N; i++)
		for(j = i + 1; j < N; j++)
			if(p[i][0] > p[j][0] && p[i][1] > p[j][1]) p[j][2]++;
			else if(p[j][0] > p[i][0] && p[j][1] > p[i][1]) p[i][2]++;

	for(i = 0; i < N; i++)
		printf("%d ", p[i][2]);
	printf("\n");
	return 0;
}
