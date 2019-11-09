#include <cstdio>

int main(void){
	char n[101];
	int i = 0, N, total = 0;
	scanf("%d", &N);
	scanf("%s", n);
	for(i = 0; i < N; i++)
		total += (n[i] - '0');
	printf("%d\n", total);
	return 0;
}
