#include <vector>
#include <cstdio>

#define INF 987654321

int main(){
	int n = 0, m = 0;
	int a, b, c;

	scanf("%d %d", &n, &m);

	int go[n+1][n+1];
	int res[n+1][n+1];

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			go[i][j] = INF;
			res[i][j] = 0;
		}
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(go[a][b] > c){
			go[a][b] = c;
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				res[i][j] = go[i][j];

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(res[i][j] > res[i][k] + res[k][j])
					res[i][j] = res[i][k] + res[k][j];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", res[i][j] == INF ? 0 : res[i][j]);
		}
		printf("\n");
	}
}