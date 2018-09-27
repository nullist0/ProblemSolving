#include <cstdio>

int main(void)
{
	int k = 0;
	scanf("%d", &k);

	for(int i = 0; i < 2*k-1; i++){
		if(i < k)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}