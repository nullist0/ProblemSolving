#include <cstdio>

int main(void){
	int N, i;
	scanf("%d", &N);
	for(i = 1; i < 10; i++)
		printf("%d * %d = %d\n", N, i, N * i);
	return 0;
}