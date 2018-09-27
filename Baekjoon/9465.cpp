#include <cstdio>
#include <algorithm>

using namespace std;
int stickers[2][100000];
int n;

int dp(){
	stickers[1][1] += stickers[0][0];
	stickers[0][1] += stickers[1][0];

	for(int i = 2; i < n; i++){
		for(int j = 0; j < 2; j++){
			stickers[j][i] += max(stickers[!j][i-1], stickers[!j][i-2]);
		}
	}

	return max(stickers[0][n-1], stickers[1][n-1]);
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t = 0; t < tc; t++){
		scanf("%d", &n);

		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &stickers[i][j]);
			}
		}

		printf("%d\n", dp());
	}

	return 0;
}