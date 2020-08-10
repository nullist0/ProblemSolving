#include <cstdio>
int main(void){
	int T, M, N, x, y, k;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d", &M, &N, &x, &y);
		//x = k % M, y = k % N
		y %= N; 
		for(k = x; k <= M * N; k+= M)
			if(k % N == y) break;
		printf("%d\n", k > M * N ? -1 : k);
	}
	return 0;
}
