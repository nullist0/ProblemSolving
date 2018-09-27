#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n, m;

	int count = 0;
	string tmp = "";
	vector<string> res;

	scanf("%d %d", &n, &m);

	vector<string> no;
	for(int i = 0; i < n + m; i++){
		cin >> tmp;
		no.push_back(tmp);
	}

	sort(no.begin(), no.end());

	for(int i = 0; i < no.size() - 1; i++){
		if(no[i] == no[i+1]){
			res.push_back(no[i]);
		}
	}

	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}
