#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int queue[10001];
int front = 0;
int back = 0;

int main(){
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "push"){
			int t = 0;
			cin >> t;
			queue[back++] = t;
		}
		if(s == "pop"){
			if(front == back){
				printf("-1\n");
			}else{
				printf("%d\n", queue[front++]);
			}
		}
		if(s == "size"){
			printf("%d\n", back - front);
		}
		if(s == "empty"){
			printf("%d\n", front == back);
		}
		if(s == "front"){
			if(back == front)
				printf("-1\n");
			else
				printf("%d\n", queue[front]);
		}
		if(s == "back"){
			if(back == front)
				printf("-1\n");
			else
				printf("%d\n", queue[back-1]);
		}
	}
}