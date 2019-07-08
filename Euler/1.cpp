#include <cstdio>

int main(){
	int b;
	int i, total = 0;
	scanf("%d", &b);
	for(i = 1; i < b; i++){
		if(i % 3 == 0 || i % 5 == 0) total += i;
	}

	printf("%d\n", total);
	return 0;
}
