#include <cstdio>
#include <algorithm>

#define MIN -1000 * 100000

using namespace std;

int n;
int arr[100000];

// Largest Sequential Sum
long long LSS() {
	long long localSum[n];
	long long globalSum = MIN;

	// localSum[k] = max(arr[k], max(0 <= i < k)(localSum[i] + sum(arr[i+1:n])))

	for(int k = 0; k < n; k++) {
		if(k == 0) {
			localSum[0] = arr[0];
		} else {
			int cache = 0;
			localSum[k] = max((long long)arr[k], localSum[k-1] + arr[k]);
		}
	}

	for(int i = 0; i < n; i++) {
		globalSum = max(globalSum, localSum[i]);
	}

	return globalSum;
}

int main(void) {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	printf("%lld\n", LSS());

	return 0;
}