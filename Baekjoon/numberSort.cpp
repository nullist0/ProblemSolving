#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	vector<int> v(n);

	for(int i = 0; i < n; i ++){
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.begin() + n);

	for(int i = n-1; i >= 0; i--){

		printf("%d\n", v[i]);

	}
}