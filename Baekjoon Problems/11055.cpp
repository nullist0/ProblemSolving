#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];
int cache[1001];
int n = 0;

int dp(int ind){
	if(cache[ind] > 0) return cache[ind];

	for(int i = ind; i < n; i++)
		if(arr[ind] < arr[i])
			cache[ind] = max(cache[ind], arr[i] + dp(i));
	return cache[ind];
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, arr[i] + dp(i));

	printf("%d\n", ans);

	return 0;
}