#include <cstdio>

int main(void){
	int H, M;
	scanf("%d %d", &H, &M);

	printf("%d %d\n", ((H - (M < 45)) + 24) % 24, (M+15) % 60);
	return 0;
}
