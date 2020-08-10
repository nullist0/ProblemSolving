//problem 2457

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int tmp[4];

int main(){

	int n = 0, k = 0;
	scanf("%d", &n);

	vector<pair<pair<int, int>, pair<int, int> > > v(n);

	for(int i = 0; i < n; i++){

		for(int j = 0; j < 4; j++)
			scanf("%d", &tmp[j]);

		v[i] = make_pair(make_pair(tmp[0], tmp[1]),
						make_pair(tmp[2], tmp[3]));
	}

	for(int i = 0; i < n; i++){
		
	}

	return 0;
}