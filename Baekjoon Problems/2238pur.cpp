#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int u, n, p, small = 999999, index = 0;
	string s;
	vector<vector<string> > d(10001);

	scanf("%d %d", &u, &n);

	for(int i = 0; i < n; i++){
		cin >> s;
		scanf("%d", &p);

		d[p-1].push_back(s);
	}

	for(int i = 0; i < u; i++){
		if(0 < d[i].size() && d[i].size() < small){
			small = d[i].size();
			index = i;
		}
	}

	cout << d[index][0];
	printf(" %d\n", index + 1);

	return 0;
}