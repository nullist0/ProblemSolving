#include <cstdio>

int d(int n){
	return n + (n / 10000) + ((n / 1000) % 10) 
		+ ((n / 100) % 10) + ((n / 10) % 10) + n % 10;
}
int n[10001];
int main(void){
	int i, cache = 1;
	for(i = 1; i <= 10000; i++){
		if(n[i]) continue;
		cache = i;
		while(cache <= 10000){
			cache = d(cache);
			n[cache] = 1;
		}
	}
	for(i = 1; i <= 10000; i++)
		if(!n[i])
			printf("%d\n", i);
	return 0;
}
