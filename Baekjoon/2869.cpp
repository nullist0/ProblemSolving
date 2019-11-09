#include <cstdio>
#define ll long long

int main(void){
	ll A, B, V, n, d;
	scanf("%lld %lld %lld", &A, &B, &V);
	n = V - A; d = A - B;
	printf("%lld\n", n%d==0 ? n/d + 1 : n/d+2);
	return 0;
}
