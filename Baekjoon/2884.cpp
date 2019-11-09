#include <cstdio>
#define nor(x) (((x) > 0) ? 0 : 1)
#define c(x, m) (((x) < 0) ? (x) + m : (x))

int main(void){
	int H, M;
	scanf("%d %d", &H, &M);
	printf("%d %d\n", c((H - nor(M-45)), 24), c((M-45), 60));
	return 0;
}
