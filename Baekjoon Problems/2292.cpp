#include <cstdio>
int main(void){
	int N, n;
	scanf("%d", &N);
	for(n = 1; N > 1 + 3 * n * (n - 1); n++);
	printf("%d\n", n);
	return 0;
}
