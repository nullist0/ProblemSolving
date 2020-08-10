#include <cstdio>

#define ll long long
#define sq(x) ((x) * (x))
int main(void){
	int T;
	ll x1, y1, r1, x2, y2, r2;
	ll d, sub, add;

	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		sub = sq(r2 - r1); add = sq(r1 + r2);
		d = sq(x1 - x2) + sq(y1 - y2);
		if(add < d || sub > d) printf("0");
		else if(add == d || (sub == d && d != 0)) printf("1");
		else if(sub < d && d < add) printf("2");
		else if(d == 0){
			if(sub == 0) printf("-1");
			else printf("0");
		}
		printf("\n");
	}

	return 0;
}
