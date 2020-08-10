#include <stack>
#include <iostream>

using namespace std;

int main(){

	string str = "";
	char t = '\0';
	int n = 0, res = 0;

	cin >> n;

	for(int i = 0; i < n; i++){
		stack<char> s;
		cin >> str;

		for(int j = 0; j < str.length(); j++){
			t = str.at(j);
			if(!s.empty()){
				if(t == 'A' && s.top() == 'A')
					s.pop();
				else if(t == 'B' && s.top() == 'B')
					s.pop();
				else
					s.push(t);
			}else{
				s.push(t);
			}
		}
		if(s.empty())
			res++;
	}

	cout << res << "\n";

	return 0;
}