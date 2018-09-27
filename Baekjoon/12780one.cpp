#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	string input = "", search = "";
	int count = 0, len = 0;

	cin >> input;
	cin >> search;

	len = search.size();

	for(int i = input.find(search); i != string::npos; i = input.find(search)){
		input = input.substr(0, i) + input.substr(i+len, input.length() - i - len);
		count ++ ;
	}

	printf("%d\n", count);
}