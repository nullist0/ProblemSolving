#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main(){

	int m, n;

	scanf("%d %d", &m, &n);

	vector<int> v(n+1);

	for(int i = 0; i < n+1; i++)
		v[i] = i;

	v[0] = -1;
	v[1] = -1;

	for(int i = 2; i <= sqrt(n); i++){
		for(int j = 2; j * i <= n; j++){
			v[j * i] = -1;
		}
	}

	for(int i = m; i < n+1; i++){
		if(v[i] > 0)
			printf("%d\n", v[i]);
	}

}