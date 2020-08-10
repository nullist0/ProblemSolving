#include <cstdio>

using namespace std;

int mod = 1000000000;
int floor[101][10];

int main(void){
	int N, ret = 0;
	scanf("%d", &N);

	floor[1][0] = 0;
	for(int i = 1; i < 10; i++)
		floor[1][i] = 1;

	for(int n = 2; n <= N; n++){
		floor[n][0] = floor[n-1][1] % mod;
		for(int i = 1; i < 9; i++)
			floor[n][i] = floor[n-1][i+1] % mod + floor[n-1][i-1] % mod;
		floor[n][9] = floor[n-1][8] % mod;
	}

	for(int i = 0; i < 10; i++){
		ret += floor[N][i] % mod;
		ret %= mod;
	}

	printf("%d\n", ret % mod);

	return 0;
}