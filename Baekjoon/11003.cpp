#include <cstdio>

int main(void){
	int arr[5000000], N, L;
	int i, D = 1000000001;

	scanf("%d %d", &N, &L);

	for(i = 0; i < N; i++){
		scanf("%d", arr + i);

		if(i < L) D = D > arr[i] ? arr[i] : D;
	}

	for(i = 0; i < N - L; i++){
		printf("%d ", D);

	}
	return 0;
}
