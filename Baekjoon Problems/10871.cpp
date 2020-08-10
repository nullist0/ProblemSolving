#include <cstdio>
int main(void){
	int i, j, M = 0, N, X, arr[10000];
	scanf("%d %d", &N, &X);
	for(i = 0; i < N; i++){
		scanf("%d", arr + M);
		if(arr[M] < X) M++;
	}
	for(j = 0; j < M; j++)
		printf("%d ", arr[j]);
	return 0;
}

