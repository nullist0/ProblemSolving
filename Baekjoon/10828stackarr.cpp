#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int stack[10001], top;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		if(s == "push"){
			int x;
			cin >> x;
			stack[top++] = x;
		}
		else if(s == "pop"){
			if(top == 0)
				printf("-1\n");
			else
				printf("%d\n", stack[--top]);
		}
		else if(s == "size"){
			printf("%d\n", top);
		}
		else if(s == "empty"){
			printf("%d\n", top == 0);
		}
		else if(s == "top"){
			if(top != 0)
				printf("%d\n", stack[top-1]);
			else
				printf("-1\n");
		}
	}
}