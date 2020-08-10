#include <cstdio>
int hanoi(int n, int from, int to){
	if(n == 0) return 0;
	int ret = 0;

	ret += hanoi(n-1, from, 6 - from - to);
	printf("%d %d\n", from, to);
	ret += hanoi(n-1, 6 - from - to, to);

	return ret + 1;
}

int main(void){
	int n;
	scanf("%d", &n);
	printf("%d\n", (1<<n) - 1);
	hanoi(n, 1, 3);
	return 0;
}
