#include <stdio.h>

typedef unsigned long long ll;

//a > b
ll gcd(ll a, ll b){
	if(a % b == 0) return b;
	if(a > b)
		gcd(b, a % b);
}

int main(void){
	ll n, i, ret;

	scanf("%lld", &n);
	
	ret = n;
	for(i = n - 1; i > 0; i--){
		printf("(%lld, %lld) = %lld\n", ret, i, gcd(ret, i));
		ret = ret * i / gcd(ret, i);
	}

	printf("%lld\n", ret);

	return 0;
}
