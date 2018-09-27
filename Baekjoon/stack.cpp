//problem 10828
#include <cstdio>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n = 0, p = 0;
	string tmp = "";
	stack<int> s;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp.find("push") != string::npos){
			scanf("%d", &p);
			s.push(p);
		}else if(tmp.find("pop") != string::npos){
			if(!s.empty()){
				printf("%d\n", s.top());
				s.pop();
			}else{
				printf("-1\n");
			}
		}else if(tmp.find("empty") != string::npos){
			printf("%d\n", s.empty() ? 1 : 0);
		}else if(tmp.find("size") != string::npos){
				printf("%d\n", (int)s.size());
		}else if(tmp.find("top") != string::npos){
			if(!s.empty()){
				printf("%d\n", s.top());
			}else{
				printf("-1\n");
			}
		}
	}
}