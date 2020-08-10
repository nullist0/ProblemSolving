#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int minSquare[100001];

int dp(int n){
	int& ret = minSquare[n];
	if(ret <= 4) return ret;
	for(int i = 1; i*i < n; i++){
		ret = min(dp(n-i*i) + dp(i*i), ret);
		if(ret == 2) break;
	}
	return ret;
}

int main(void){
	int n = 0;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		int sq = sqrt(i);
		minSquare[i] = 5;
		if(sq * sq == i)
			minSquare[i] = 1;
	}

	printf("%d\n", dp(n));

	return 0;
}