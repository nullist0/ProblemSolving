#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int n = 0;
	string s = "";
	vector<pair<int, string> > v(20000);

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin >> v[i].second;
		v[i].first = v[i].second.length();
	}

	sort(v.begin(), v.begin() + n);
	for(int j = 0; j < n; j++){
		if(s != v[j].second)
			printf("%s\n", v[j].second.c_str());
		s = v[j].second;
	}
}