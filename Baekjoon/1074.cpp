#include <cstdio>
#include <vector>

int r, c, ans;

void explore(int len){
	if(len == 1)
		return;
	ans += (2 * (r >= len/2) + (c >= len/2))*(len/2) * (len/2);
	r -= len/2 * (r >= len/2);
	c -= len/2 * (c >= len/2);
	explore(len/2);
}

int main(void){
	int N;
	scanf("%d %d %d", &N, &r, &c);

	explore(1 << N);

	printf("%d\n", ans);

	return 0;
}