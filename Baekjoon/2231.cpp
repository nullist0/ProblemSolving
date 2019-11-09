#include <cstdio>

int d(int n){
	int m = n;
	for(int i = 1; i <= 1e7; i *= 10)
		m += (n/i) % 10;
	return m;
}

int main(void){
	int N, f = 0;
	scanf("%d", &N);
	for(int i = 0; i <= N; i++)
		if(d(i) == N){ 
			f = i; 
			break; 
		}
	printf("%d\n", f ? f : 0);
	return 0;
}
