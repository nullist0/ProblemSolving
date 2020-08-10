#include <cstdio>
#include <stdlib.h>

int main(void){
	int mat[1000][1000];
	int tc, n, res;

	scanf("%d", &tc);

	for(int i = 0; i < tc; i++){
		res = 0;

		scanf("%d", &n);
		/*
		for(int j = 0; j < n; j++){
			for(int k = j + 1; k < n; k++){
				scanf("%d", &mat[j][k]);
				mat[k][j] = mat[j][k];
			}
		}
		*/
		//Input End

		int cnt = 0;
		for(int j = 0; j < n; j++){
			for(int k = j+1; k < n; k++){
				for(int l = k+1; l < n; l++){
					cnt++;
					if(j == k || k == l || j == l) continue;
					//if(cache[k] + cache[j] + cache[l] == (i + 1) * 3) continue;
					if(mat[j][k] == mat[k][l] && mat[k][l] == mat[j][k]){
					//	cache[j] = cache[k] = cache[l] = i+1;
						res++;
					}
				}
			}
		}
		printf("%d\n", cnt);//res);
	}

	return 0;
}