#include <cstdio>
int main(void){
	int T, x, A, B;
	scanf("%d", &T);
	for(x = 1; x <= T; x++){
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", x, A+B);
	}
	return 0;
}
