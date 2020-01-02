#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100002];

int main(void){
	int cache, n, p = 0;
	int res = -1000 * 100001;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &cache);
		if(res < cache) res = cache;
		if(cache == 0) continue;
		if(cache * arr[p] >= 0){
			arr[p] += cache;
		}else{
			p++;
			arr[p] += cache;
		}
	}

	printf("before: ");
	for(int i = 0; i <= p; i++)
		printf("%d ", arr[i]);
	printf("\n");

	for(int i = 0; i <= p;){
		if(arr[i] > res) res = arr[i];
		if(arr[i] < 0){
			i++;
			continue;
		}
		if(arr[i] < arr[i] + arr[i+1] + arr[i+2] && arr[i+2] < arr[i] + arr[i+1] + arr[i+2]){
			arr[i+2] = arr[i] + arr[i+1] + arr[i+2];
			i += 2;
			if(arr[i] > res) res = arr[i];
		}else{
			i++;
		}
	}
	printf("after: ");
	for(int i = 0; i <= p; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("%d\n", res);
	return 0;
}