#include <cstdio>
#define inv(x) (x)/100 + (((x)/10) % 10) * 10 + ((x)%10)*100

int main(void){
	int A, B;
	scanf("%d %d", &A, &B);
	A = inv(A); B = inv(B);
	printf("%d\n", A < B ? B : A);
	return 0;
}
