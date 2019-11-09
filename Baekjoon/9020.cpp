#include <cstdio>
#define N 10000
int com[N+1];
int main(void){
	int i, j, T, n, p1, p2;
	com[1] = 1;
	for(i = 2; i <= N; i++){
		j = i;
		while((j+=i) <= N)
			com[j] = 1;
	}
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		p1 = 1; p2 = n-1;
		for(i = 2; 2 * i <= n; i++){
			if(com[i] + com[n-i] == 0){
				if((n - 2 * i) < p2 - p1){
					p1 = i; p2 = n-i;
				}
			}
		}
		printf("%d %d\n", p1, p2);
	}
	return 0;
}
