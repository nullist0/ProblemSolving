#include <cstdio>
#include <algorithm>

using namespace std;

#define Great 0
#define Less 1

int arr[1001];
int cache[1001][2];
int n;

int dp(int s, int flag){
	int& ret = cache[s][flag];
	if(ret != 0) return ret;

	ret = 1;
	for(int i = s+1; i < n; i++){
		if(flag == Great && arr[s] < arr[i]){
			ret = max(ret, dp(i, Great) + 1);
			ret = max(ret, dp(i, Less) + 1);
		}
		else if(flag == Less && arr[s] > arr[i]){
			ret = max(ret, dp(i, Less) + 1);
		}
	}

	return ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int ans = 0;

	for(int i = 0; i < n; i++){
		ans = max(ans, dp(i, Great));
		ans = max(ans, dp(i, Less));
	}

	printf("%d\n", ans);

	return 0;
}