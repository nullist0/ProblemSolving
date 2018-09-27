#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

string str;
int n = 0;

int bracket(int cur, int nu, int res){
	if(cur == n-1) return res;

	char c1 = str.at(cur), c2 = str.at(cur + 1);

	if(c1 == ')'){
		if(nu/2 != 0)
			return bracket(cur+1, nu/2, res);
		else
			return bracket(cur+1, 1, res);
	}
	else if(c1 == ']'){
		if(nu/3 != 0)
			return bracket(cur+1, nu/3, res);
		else
			return bracket(cur+1, 1, res);
	}
	else{
		if(c1 == '('){
			if(c2 == ')')
				return bracket(cur+1, nu * 2, res + nu*2);
			return bracket(cur+1, nu * 2, res);
		}else if(c1 == '['){
			if(c2 == ']')
				return bracket(cur+1, nu * 3, res + nu*3);
			return bracket(cur+1, nu * 3, res);
		}
	}
}

int main(){
	char t = -1;
	int l = 0;
	stack<char> s, res;

	cin >> str;

	n = str.length();

	s.push(str.at(0));

	for(int i = 1; i < str.length(); i++){
		t = str.at(i);
		if(t == ']' && s.top() == '['){
			s.pop();
		}
		else if(t == ')' && s.top() == '('){
			s.pop();
		}
		else{
			s.push(t);
		}
	}

	if(s.empty())
		printf("%d\n", bracket(0, 1, 0));
	else
		printf("0\n");
}