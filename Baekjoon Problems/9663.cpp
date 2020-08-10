#include <cstdio>
#include <cmath>

using namespace std;

int col[16];
int N = 0;
int res = 0;

int promising(int j){
	for(int i = 0; i < j; i++){
		if(col[i] == col[j] || abs(col[i] - col[j]) == abs(i-j))
			return 1;
	}
	return 0;
}

void nQueens(int n){
	if(n == N){
		res++;
		return;
	}
	for(int i = 0; i < N; i++){
		col[n] = i;
		if(!promising(n)){
			nQueens(n+1);
		}
	}
}

int main(void){
	scanf("%d", &N);
	nQueens(0);
	printf("%d\n", res);
	return 0;
}