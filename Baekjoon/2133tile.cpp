#include <cstdio>

using namespace std;

#define THREE 0
#define TWO 1

int tile[31][2];

int main(void){
	int n = 0;
	scanf("%d", &n);

	tile[1][TWO] = 1;
	tile[2][TWO] = 2;

	tile[2][THREE] = 3;
	tile[4][THREE] = 11;

	for(int i = 3; i <= n; i++)
		tile[i][TWO] = tile[i-1][TWO] + tile[i-2][TWO];
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1) continue;
		tile[i][THREE] = tile[i][TWO] * 
	}

	printf("%d\n", tile[n][THREE]);

	return 0;
}