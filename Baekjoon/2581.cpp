#include <cstdio>

int primes[10001];

int main(void){
	int i, j, M, N, total = 0, mp = 0;
	primes[1] = 1;
	for(i = 2; i <= 10000; i++){
		j = i;
		if(!primes[j])
			while((j += i) <= 10000)
				primes[j] = 1;
	}
	scanf("%d %d", &M, &N);
	for(i = M; i <= N; i++){
		if(!primes[i]){ 
			if(mp == 0) mp = i;
			total += i;
		}
	}
	if(total) printf("%d\n%d\n", total, mp);
	else printf("%d\n", -1);
	
}
