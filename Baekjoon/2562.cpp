#include <cstdio>

int main(void){
	int M = 0, Mi = 1, i;
	int cache;
	for(i = 1; i <= 9; i++){
		scanf("%d", &cache);
		if(cache > M){
			M = cache;
			Mi = i;
		}
	}
	printf("%d\n%d\n", M, Mi);
	return 0;
}
