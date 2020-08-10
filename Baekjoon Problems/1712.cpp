#include <cstdio>
#define ll long long

int main(void){
	ll A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	if(C <= B) printf("-1\n");
	else printf("%lld\n", A/(C-B) + 1);
	return 0;
}
