#include <cstdio>

int main(void){
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	while(a != 0 || b != 0 || c != 0){
		a = a * a; b = b * b; c = c * c;
		if(a+b == c || b+c == a || a+c == b) printf("right\n");
		else printf("wrong\n");
		scanf("%lld %lld %lld", &a, &b, &c);
	}
	return 0;
}
