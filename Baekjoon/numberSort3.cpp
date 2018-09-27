#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int n = 0, tmp;

	vector<pair<int, int> > v(10000);

	scanf("%d", &n);

	for(int i = 0; i < 10000; i++)
		v[i] = make_pair(i, 0);

	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		v[tmp-1].second++;
	}

	for(int i = 0; i < 10000; i++){

		if(v[i].second > 0)
			for(int j = 0; j < v[i].second; j++)
				cout << i+1 << '\n';

	}
}