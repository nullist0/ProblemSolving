//problem 2805

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	vector<int> tree;

	int n = 0, m = 0;
	int height;
	int res = 0;

	int cache = 0;
	int low = 0, high = 0, mid;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &height);
		tree.push_back(height);
		high = max(high, height);
	}

	mid = (low + high) / 2;
	while(low < high && high - low > 1){
		cache = 0;
		for(int i = 0; i < n; i++)
			cache += tree[i] > mid ? tree[i] - mid : 0;

		if(cache > m)
			low = mid;
		else if(cache < m)
			high = mid;
		else
			break;

		mid = (low + high) / 2;
	}
	res = mid;

	printf("%d\n", mid);

	return 0;
}