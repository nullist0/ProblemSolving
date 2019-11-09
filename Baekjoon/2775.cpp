#include <cstdio>
int map[15][15];

int main(void){
	int a, b, T, k, n;
	for(b = 1; b < 15; b++) map[0][b] = b;
	for(a = 1; a < 15; a ++)
		for(b = 1; b < 15; b++)
			map[a][b] = map[a][b-1] + map[a-1][b];
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &k, &n);
		printf("%d\n", map[k][n]);
	}
	return 0;
}
