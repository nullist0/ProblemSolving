#include <cstdio>
#define sum(n) ((n) * ((n) + 1) / 2)

int main(void){
	int X, n, m, d, offset;
	scanf("%d", &X);
	for(n = 1; sum(n-1) > X || X > sum(n); n++);
	offset = X - sum(n-1);
	if(n%2 == 0){ m = offset; d = n - offset + 1; }
	else { m = n - offset + 1; d = offset; }
	printf("%d/%d\n", m, d);
	return 0;
}
	
