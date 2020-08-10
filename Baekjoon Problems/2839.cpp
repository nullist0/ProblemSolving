#include <cstdio>

int main(void){
	int N, m, ret = 10000;
	scanf("%d", &N);

	//N = 3n+5m, m+n is minimum
	//n = N - 5m / 3, m + n = m + (N-5m)/3, N/5 > m > 0
	for(m = 0; m <= N/5; m++)
		if((N - 5*m) % 3 == 0 && ret > m + (N - 5*m)/3)
			ret = m + (N-5*m) / 3;
	printf("%d\n", ret == 10000 ? -1 : ret);
	return 0;
}
