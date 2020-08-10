#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	vector<pair<int, int> > v(100000);
	int n = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[i] = make_pair(x, y);
	}

	sort(v.begin(), v.begin() + n);

	for(int i = 0; i < n; i++){
		printf("%d %d\n", v[i].first, v[i].second);
	}
}