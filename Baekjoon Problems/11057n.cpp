#include <cstdio>

using namespace std;

const int mod = 10007;

int rising[10];

int main(void){
	int n, ret = 0;

	scanf("%d", &n);

	for(int i = 0; i < 10; i++){
		rising[i] = 1;
	}

	for(int size = 2; size <= n; size++){
		for(int i = 9; i >= 0; i--){
			int total = 0;

			for(int j = 0; j <= i; j++){
				total += rising[j];
			}

			rising[i] = total % mod;
		}
	}

	for(int i = 0; i < 10; i++){
		ret += rising[i] % mod;
	}

	printf("%d\n", ret % mod);

	return 0;
}