#include <cstdio>
#define N 300000
int com[N];

int main(void){
	int i, j, n, m, ret = 0;
	com[1] = 1;
	for(i = 2; i <= N; i++){
		j = i;
		while((j+=i) <= N)
			com[j] = 1;
	}
	scanf("%d", &n);
	while(n){
		ret = 0;
		for(i = n+1; i <= 2 * n; i++)
			ret += !com[i];
		printf("%d\n", ret);
		scanf("%d", &n);
	}
	return 0;
}
