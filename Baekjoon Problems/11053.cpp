#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[1001];

int dp() {
	int globalLIS = 0;
	int localLIS[N];
	int cache = 0;

	for(int i = 0; i < N; i++) {
		cache = 0;
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i]) {
				cache = max(localLIS[j], cache);
			}
		}
		localLIS[i] = cache + 1;

		globalLIS = max(globalLIS, localLIS[i]);
	}
	return globalLIS;
}

int LIS() {
	int localLIS[N][N];
	int globalLIS = 0;

	for(int n = 0; n < N; n++) {
		localLIS[n][n] = 1;
		if(n < N - 1) {
			localLIS[n][n+1] = arr[n] < arr[n+1] ? 2 : 0;
		}
	}

	for(int n = 0; n < N; n++) {
		for(int m = n+2; m < N; m++) {
			localLIS[n][m] = 0;

			for(int i = n+1; i < m; i++) {
				for(int j = i; j < m; j++) {
					if(arr[n] < arr[i] && arr[j] < arr[m]) {
						localLIS[n][m] = max(localLIS[n][m], localLIS[i][j] + 2);
					}
				}
			}
		}
	}

	for(int n = 0; n < N; n++) {
		for(int m = n; m < N; m++) {
			globalLIS = max(globalLIS, localLIS[n][m]);
		}
	}

	return globalLIS;
}

int main(void){
	scanf("%d", &N);

	for(int i = 0; i < N; i ++) {
		scanf("%d", arr + i);
	}

	printf("%d\n", LIS());

	return 0;
}