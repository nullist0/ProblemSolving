#include <cstdio>

using namespace std;

int plus[12];

int dp(int n){
	if(plus[n] > 0) return plus[n];
	return dp(n-1) + dp(n-2) + dp(n-3);
}

int main(void){
	int tc, n;

	scanf("%d", &tc);

	plus[1] = 1;
	plus[2] = 2;
	plus[3] = 4;

	for(int t = 0; t < tc; t++){
		scanf("%d", &n);
		printf("%d\n", dp(n));
	}

	return 0;
}