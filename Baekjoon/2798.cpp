#include <cstdio>
int main(void){
	int i, j, k, N, M, arr[101], m = 0, cache;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) scanf("%d", arr + i);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			for(k = 0; k < N; k++){
				if(i != j && j != k && i != k){
					cache = arr[i] + arr[j] + arr[k];
					if(M - m > M - cache && M >= cache) m = cache;
				}
			}
		}
	}
	printf("%d\n", m);
	return 0;
}
