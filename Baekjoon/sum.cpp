#include <stdio.h>

int main(void){

	int n = 0;
	int sum = 0;

	scanf("%d", &n);

	//printf("%d\n", n*(n+1)/2);

	for(int i = 0; i < n; i++){
		sum += (i+1);
	}

	printf("%d\n", sum);

	return 0;
}