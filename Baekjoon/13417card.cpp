#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	int t = 0;
	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		int n = 0;

		scanf("%d", &n);
		vector<char> l(n);
		string res = "";

		for(int j = 0; j < n; j++){
			cin >> l[j];
		}

		for(int k = 0; k < n; k++){
			string t1 = l[k]+res, t2 = res+l[k];

			if(t1.compare(t2) < 0){
				res = t1;
			}else{
				res = t2;
			}
		}

		cout << res << endl;
	}
}