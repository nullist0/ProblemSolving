#include <iostream>
#include <stack>

using namespace std;

int main(){

	int n = 0;
	string str = "";

	cin >> n;

	for(int i = 0 ; i < n; i++){
		stack<char> ss;
		cin >> str;

		for(int j = 0; j < str.length(); j++){
			char t = str.at(j);
			if(!ss.empty()){
				if(t == ')' && ss.top() == '(')
					ss.pop();
				else
					ss.push(t);
			}else{
				ss.push(t);
			}
		}

		if(ss.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}