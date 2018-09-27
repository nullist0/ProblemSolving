#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	char tc = 0;
	int n, tn = 0;
	scanf("%d", &n);
	string tmp = "";

	vector<pair<int, pair<int, string> > > v(n);

	for(int i = 0; i < n; i++){

		tn = 0;
		cin >> tmp;

		for(int j = 0; j < tmp.length(); j++){
			tc = tmp.at(j);
			if('0' <= tc && tc <= '9')
				tn += tc - '0';
		}

		v[i] = make_pair(tmp.length(), make_pair(tn, tmp));
	}

	sort(v.begin(), v.begin()+n);

	for(int i = 0; i < n; i++){
		cout << v[i].second.second << '\n';
	}

}