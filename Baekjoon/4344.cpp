#include <cstdio>

int main(void){
	int C, i;
	scanf("%d", &C);
	for(i = 0; i < C; i++){
		int N, arr[1000], total = 0, j, ret = 0;
		scanf("%d", &N);
		for(j = 0; j < N; j++){
			scanf("%d", arr + j);
			total += arr[j];
		}
		for(j = 0; j < N; j++)
			ret += (total < arr[j] * N);
		printf("%.3lf%%\n", (double)ret/N * 100);
	}
	return 0;
}
