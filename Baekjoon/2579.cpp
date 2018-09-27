#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int steps[301];
int cache[301];

int dp(){
	cache[0] = steps[0];
	if(n > 1) cache[1] = steps[0] + steps[1];
	if(n > 2) cache[2] = max(steps[0] + steps[2], steps[1] + steps[2]);

	for(int i = 3; i < n; i++){
		cache[i] = steps[i] + 
			max(cache[i-2], cache[i-3] + steps[i-1]);
	}
	return cache[n-1];
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &steps[i]);

	printf("%d\n", dp());

	return 0;
}