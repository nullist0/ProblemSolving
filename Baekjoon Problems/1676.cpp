#include <cstdio>

using namespace std;

int cache[501];

int solve(int n){
	int ret = 0, div = 5;

	for(int i = 0; i <= n; i++){
		ret += n / div;
		div *= 5;
	}

	return ret;
}

int main(void){
	int N;
	scanf("%d", &N);

	printf("%d\n", solve(N));

	return 0;
}