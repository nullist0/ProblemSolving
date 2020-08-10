#include <cstdio>

using namespace std;

int factorial(int n){
	int ret = 1;
	for(int i = 2; i <= n; i++){
		ret *= i;
	}
	return ret;
}

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", factorial(N)/factorial(N-K)/factorial(K));

	return 0;
}