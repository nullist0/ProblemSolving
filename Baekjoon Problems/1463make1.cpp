#include <cstdio>
#include <algorithm>

using namespace std;

int res[1000001];

int main(){
	int n = 0;
	scanf("%d", &n);

	for(int i = 2; i <= n; i++){
		res[i] = res[i-1] + 1;

		if(i % 2 == 0){
			res[i] = min(res[i], res[i/2]+1);
		}
		if(i % 3 == 0){
			res[i] = min(res[i], res[i/3]+1);
		}
	}

	printf("%d\n", res[n]);
}