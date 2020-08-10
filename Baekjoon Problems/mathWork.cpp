#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

	char t = 0;
	string input = "", tmp = "";
	int n = 0, c = 0;

	vector<int> v(n);

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

		cin >> input;

		for(int j = 0; j < input.length(); j++){

			t = (char)input[j];

			if((int)'0' <= (int)t && (int)t <= (int)'9')
				tmp += t;
			else if(tmp.length() > 0){
				v[c] = atoi(tmp.c_str());
				tmp = "";
				c++;
			}
		}
	}

	sort(v.begin(), v.begin()+c);

	for(int i = 0; i < c; i++){
		printf("%d\n", v[i]);
	}
}