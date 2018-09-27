#include <cstdio>

int main(void)
{
	int n, res;

	for(int i = 1; ; i++){
		res = 0;
		scanf("%d", &n);
		if(n == 0) break;

		while(n > 0)
			res = res + (n = n / 5);

		printf("Case #%d: %d\n", i, res);
	}

	return 0;
}