#include <cstdio>

int main(void){
	int total, price, i;

	scanf("%d", &total);
	for(i = 0; i < 9; i++){
		scanf("%d", &price);
		total -= price;
	}

	printf("%d\n", total);
	return 0;
}
