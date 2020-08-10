#include <cstdio>

using namespace std;

int main(void){
	//n!/(n-k+1)!(k-1)! * (n-k+1)/k
	int n, m;
	long double ret = 1;

	scanf("%d %d", &n, &m);

	for(int k = 1; k <= m; k++){
		ret = (ret * (n - k + 1)) / k;
	}

	printf("%Lf\n", ret);
	return 0;
}