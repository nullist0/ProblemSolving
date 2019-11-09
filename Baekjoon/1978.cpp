#include <cstdio>
int primes[1001];
int main(void){
	int i, j, N, n, ret = 0;
	primes[1] = 1;
	for(i = 2; i <= 1000; i++){
		j = i;
		while((j+=i) <= 1000)
			if(!primes[j])
				primes[j] = 1;
	}
	scanf("%d", &N);
	while(N--){
		scanf("%d", &n);
		ret += !primes[n];
	}
	printf("%d\n", ret);
	
	return 0;
}
