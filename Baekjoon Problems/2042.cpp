#include <cstdio>

int main(void){
	int N, M, K, i, j;
	long long arr[1000000];
	int a, b; long long c;
	long long d;

	scanf("%d %d %d", &N, &M, &K);

	for(i = 0; i < N; i++)
		scanf("%lld", arr + i);

	for(; i < N + M + K; i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a == 1) arr[b-1] = c;
		else{
			d = 0;
			for(j = b-1; j < c; j++)
				d += arr[j];
			printf("%lld\n", d);
		}
	}

	return 0;
}
