#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int n, m, tmp;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

		scanf("%d", &m);

		// m = 2k+1
		int c = 0;
		vector<int> v(m);
		vector<int> res((m+1)/2);

		for(int j = 0; j < m; j++){

			scanf("%d", &tmp);

			v[j] = tmp;

			if(j%2 == 0){
				sort(v.begin(), v.begin() + j + 1);
				res[c] = v[j/2];
				c++;
			}
		}

		//print
		printf("%d\n", c);
		for(int j = 0; j < (m+1)/2; j++){
			printf("%d", res[j]);
			if((j+1)%10 == 0)
				printf("\n");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}