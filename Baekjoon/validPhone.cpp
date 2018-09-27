#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
/*
	string s1 = "9111234124124";
	string s2 = "911";

	if(s1.find(s2) != string::npos)
		cout << "in s1" << endl;
*/

	string tmp = "";

	int n = 0, m = 0;
	bool close = false;

	scanf("%d", &n);

	vector<bool> res(n);

	for(int i = 0; i < n; i ++){

		scanf("%d", &m);

		res[i] = false;

		vector<pair<int,string> > v(m);

		for(int j = 0; j < m; j++){
			cin >> tmp;
			v[j] = make_pair(tmp.at(0)-'0', tmp);
		}

		sort(v.begin(), v.begin()+m);

		for(int j = 0; j < m-1; j++){
			res[i] = (v[j].first == v[j+1].first) &&
				(v[j].second == v[j+1].second
					.substr(0, v[j].second.length()));

			if(res[i])
				break;
		}
	}

	//print
	for(int i = 0; i < n; i++){

		if(!res[i])
			printf("YES\n");
		else
			printf("NO\n");

	}
}