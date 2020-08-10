#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n = 0;

vector<int> v;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < (int)pow(2, n) - 1; i++){
		int t = 0;
		scanf("%d", &t);
		v.push_back(t);
	}
	for(int i = (int)pow(2, n-1); i != 0; i/=2){
		for(int j = 0; j < (int)pow(2,n) - 1; j++){
			if((j+1) % i == 0 && v[j] != -1){
				printf("%d ", v[j]);
				v[j] = -1;
			}
		}
		printf("\n");
	}
}

//               k 1
//       f               c 2
//   s       h       z       b 4
// a   d   g   j   l   x   v   n 8