#include <cstdio>

using namespace std;

int tile[31];

int main(void){
	int N, i, j;
	scanf("%d", &N);

	tile[0] = 1;
	for(i = 1; i <= N; i++){
		tile[i] = 0;
		if(i % 2 == 0){
			if(i >= 2) tile[i] = 3*tile[i-2];
			for(j = 4; j <= i; j+=2){
				tile[i] += 2*tile[i - j];
			}
		}
	}

	printf("%d\n", tile[N]);

	return 0;
}
