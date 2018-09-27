#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
int cache[100001];
int n;

int dp(int s){
	int ret = 0;
	for(int i = s; i < n; i++){
		if(arr[i] >= 0){
			ret += arr[i];
			cache[i] = 1;
		}
		else
			break;
	}
	return ret;
}

int main(void){
	int ans = -1000;
	vector<int> list;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
		ans = max(ans, arr[i]);
	}

	if(ans > 0){
		for(int i = 0; i < n; i++){
			int c;
			if(arr[i] > 0 && cache[i] == 0){
				c = dp(i);
				ans = max(ans, c);
				list.push_back(c);
			}
			else if(arr[i] < 0 && cache[i] == 0)
				list.push_back(arr[i]);
		}
	}

	for(int i = 0; i < list.size(); i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("%d\n", ans);

	return 0;
}