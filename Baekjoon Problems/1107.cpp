#include <cstdio>
#include <cmath>

int p[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int click(int n){
	int i = 1, j = 0, ret = 1;
	if(n == 0) return p[0];
	for(i = 1; n / i; i *= 10)
		ret = ret && p[(n / i) % 10];
	return ret;
}

int log(int n){
	int i = 1, j = 0;
	if(n == 0) return 1;
	for(i = 1; n / i; i *= 10) j++;
	return j;
}

int main(void){
	int N, M;
	int i, cache, flag = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	while(M--){
		scanf("%d", &cache);
		p[cache]--;
	}
	flag = -1;
	i = 0;
	while(1){
		if(N - i == 100 || N + i == 100) flag = i;
		else if(click(N - i)) flag = i + log(N - i);
		else if(click(N + i)) flag = i + log(N + i);
		if(flag >= 0) break;
		i++;
	}
	printf("%d\n", flag > abs(100-N) ? abs(100-N) : flag);
	return 0;
}

