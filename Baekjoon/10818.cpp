#include <cstdio>

int main(void){
	int i, cache;
	int N, M = -1000000, m = 1000000;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &cache);
		m = cache < m ? cache : m;
		M = cache > M ? cache : M;
	}
	printf("%d %d\n", m, M);
	return 0;
}

