#include <cstdio>

using namespace std;

int tri[501][501];

int main(void){
	int n = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			scanf("%d", &tri[i][j]);

	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){

		}
	}

	return 0;
}