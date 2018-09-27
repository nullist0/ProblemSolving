#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1001];
int cache[1001];
int n;

int dp(int s){
	int& ret = cache[s];
	if(ret != 0) return ret;

	ret = 1;
	for(int i = s+1; i < n; i++)
		if(arr[s] > arr[i])
			ret = max(ret, dp(i) + 1);

	return ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, dp(i));

	printf("%d\n", ans);

	return 0;
}