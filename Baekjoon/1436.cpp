#include <cstdio>

int has666(long long x){
	while(x > 0){
		if(x % 1000 == 666)
			return 1;
		x = x / 10;
	}
	return 0;
}

int main(void){
	int N;
	long long n = 1;
	scanf("%d", &N);

	for(n = 1; N>0; n++){
		if(has666(n)) N--;
	}
	printf("%lld\n", n-1);
	return 0;
}
