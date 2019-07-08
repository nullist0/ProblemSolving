#include <cstdio>
#include <cmath>

#define MAX 100000000

typedef unsigned long long ll;

int checkPrime(ll m){
	ll limit = sqrt(m);
	ll i;
	for(i = 2; i < limit; i++){
		if(m % i == 0)
			return 0;
	}
	return 1;
}

int main(void){
	ll n, i, lim, lpf = 2;
	scanf("%lld", &n);

	lim = n;
	//lim = sqrt(n);
	
	if(lim % 2 == 0) lim++;
	else lim += 2;

	for(i = lim; i > 1; i -= 2){
		if(n % i == 0 && checkPrime(i)){
			lpf = i;
			break;
		}
	}

	printf("%lld\n", lpf);

	return 0;
}
