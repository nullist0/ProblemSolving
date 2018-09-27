#include <cstdio>
#include <algorithm>

using namespace std;

int bottle[10001];
int n;

int dp(){
	int drink[10001];
	
	if(n > 0)
		drink[0] = bottle[0];
	if(n > 1)
		drink[1] = bottle[0] + bottle[1];
	if(n > 2)
		drink[2] = max(max(bottle[0], bottle[1]) + bottle[2], drink[1]);

	for(int i = 3; i < n; i++){
		drink[i] = max(max(drink[i-2], drink[i-3] + bottle[i-1]) + bottle[i], drink[i-1]);
	}

	return drink[n-1];
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &bottle[i]);

	printf("%d\n", dp());

	return 0;
}