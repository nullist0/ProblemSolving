#include <cstdio>
#include <vector>

using namespace std;

int z[41], o[41];

int main(){
	int n = 0, t = 0;

	scanf("%d", &n);

	for(int i = 0 ; i < 41; i++){
		z[i] = -1; o[i] = -1;
	}

	z[0] = 1; o[0] = 0;
	z[1] = 0; o[1] = 1;

	for(int i = 0; i < n; i++){
		scanf("%d", &t);

		if(z[t] == -1 && o[t] == -1){
			for(int i = 2; i <= t; i++){
				z[i] = z[i-1] + z[i-2];
				o[i] = o[i-1] + o[i-2];
			}
		}
		printf("%d %d\n", z[t], o[t]);
	}
}