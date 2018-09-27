#include <cstdio>

using namespace std;

int main(void){
	int N;
	long long num[91][2];

	scanf("%d", &N);

	num[1][0] = 0;
	num[1][1] = 1;

	for(int n = 2; n <= N; n++){
		num[n][0] = num[n-1][0] + num[n-1][1];
		num[n][1] = num[n-1][0];
	}

	printf("%lld\n", num[N][0] + num[N][1]);

	return 0;
}