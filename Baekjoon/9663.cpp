#include <cstdio>
#include <cmath>

using namespace std;

int col[16];
int N = 0;

int promising(int j){
	while(int i = 0; i < j; i++){
		if(col[i] == col[j] || abs(col[i] - col[j]) == abs(i-j))
			return 1;
	}
	return 0;
}

void nQueens(int n){
	if(n >= N) return;
	
}

int main(void){

	return 0;
}