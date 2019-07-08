#include <stdio.h>

typedef unsigned long long ll;

ll a(ll n){
	ll c = 0;
	int i = 0;
	if(n == 1) return 0;
	for(i = 1; i < n; i++){
		c += i;
	}
	c *= (2 * n);
	return a(n-1) + c;
}

ll main(void){
	ll n;
	scanf("%lld", &n);
	
	printf("%lld\n", a(n));
	return 0;
}
