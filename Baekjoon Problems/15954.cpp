#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
	int dolls[501];
	vector<long double> v;

	int N, K, input;
	long double result = 100000 * 500;

	scanf("%d %d", &N, &K);

	for(int i = 0; i < N; i++){
		scanf("%d", &dolls[i]);
	}

	//sort(dolls.begin(), dolls.end());

	for(int k = K; k <= N; k++){
		for(int j = 0; j <= N-k; j++){
			long double mean = 0;
			long double derv = 0;
			long double cache = 0;
			for(int l = 0; l < k; l++){
				mean += dolls[j + l];
			}

			mean = mean / k;

			for(int l = 0; l < k; l++){
				cache = abs(dolls[j + l] - mean);
				derv += cache * cache / k;
			}

			v.push_back(derv);
		}
	}

	sort(v.begin(), v.end());

	printf("%.11Lf\n", sqrt(v[0]));
	return 0;
}