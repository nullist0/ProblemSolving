#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int check_cut(int height, int n, int goal, int *tree) {
	long long total = 0;
	for(int i = 0; i < n; i++) {
		total += max(0, tree[i] - height);
	}

	return total >= goal;
}

int main(void) {
	int N, M, height;
	int trees[1000000];

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++) {
		scanf("%d", trees + i);
	}

	{
		int low = 0, high = 2000000000;
		int mid;

		while((mid = (low + high) / 2) != low) {
			if(check_cut(mid, N, M, trees)) {
				low = mid;
			} else {
				high = mid;
			}
		}

		height = low;
	}

	printf("%d\n", height);

	return 0;
}