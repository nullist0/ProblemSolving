#include <cstdio>

int main(void){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	if((B - A) * (C - A) <= 0) printf("%d\n", A);
	else if((A - B) * (C - B) <= 0) printf("%d\n", B);
	else printf("%d\n", C);
	
	return 0;
}
