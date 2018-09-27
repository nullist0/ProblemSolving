#include <cstdio>

using namespace std;

int combination[1001][1001];

int combi(int n, int k){

	for(int m = 1; m <= n; m++){
		combination[m][0] = 1;
		combination[m][m] = 1;
		for(int l = 1; l < m; l++){
			combination[m][l] = combination[m-1][l-1] + combination[m-1][l];
			combination[m][l] %= 10007;
		}
	}

	return combination[n][k];
}

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", combi(N, K));

	return 0;
}