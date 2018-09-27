#include <cstdio>

int process(int t){
	int tt = 0;
	tt = t/10 + t%10;
	t = (t*10 + tt%10)%100;
	return t;
}

int main(void){
	int n = 0, tmp = 0, count = 0;

	scanf("%d", &n);

	tmp = n;
	tmp = process(tmp);
	for(count = 1; tmp != n; count++){
		tmp = process(tmp);
	}

	printf("%d\n", count);

	return 0;
}