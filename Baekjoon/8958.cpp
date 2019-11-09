#include <cstdio>
int main(void){
	int N, i;
	char T[81];
	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%s", T);
		int j = 0, ret = 0, cache = 0;
		while(T[j]){
			if(T[j] == 'O') cache++;
			else cache = 0;
			ret += cache;
			j++;
		}
		printf("%d\n", ret);
	}
	return 0;
}

