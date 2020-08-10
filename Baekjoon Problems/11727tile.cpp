#include <cstdio>

using namespace std;

int mod = 10007;

int main(void){
	int n;
	int tile[1001];
	scanf("%d", &n);

	tile[1] = 1;
	tile[2] = 3;

	for(int i = 3; i <= n; i++){
		tile[i] = tile[i-1] + 2 * tile[i-2];
		tile[i] %= mod;
	}

	printf("%d\n", tile[n]);

	return 0;
}