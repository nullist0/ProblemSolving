#include <cstdio>

int main(void){
	int N, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		for(j = N-1; j >= 0; j--)
			if(i >= j) printf("*");
			else printf(" ");
		printf("\n");
	}
	return 0;
}
