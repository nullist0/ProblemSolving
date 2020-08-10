#include <cstdio>
int main(void){
	int i, N, M = 0, total = 0, cache;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &cache);
		total += cache;
		if(cache > M) M = cache;
	}
	printf("%lf\n", (double)total/M*100/N);
	return 0;
}
