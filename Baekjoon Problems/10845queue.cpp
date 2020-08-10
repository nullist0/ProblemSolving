#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(){

	int n = 0, p = 0;
	string tmp = "", ss = "";
	queue<int> q;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

		cin >> tmp;
		if(tmp.find("push") != string::npos){
			cin >> tmp;
			p = (int)atoi(tmp.c_str());
			q.push(p);

		}else if(tmp.find("pop") != string::npos){
			if(!q.empty()){
				printf("%d\n", q.front());
				q.pop();
			}else{
				printf("-1\n");
			}

		}else if(tmp.find("size") != string::npos){
			cout << q.size() << "\n";

		}else if(tmp.find("empty") != string::npos){
			if(!q.empty()){
				printf("0\n");
			}else{
				printf("1\n");
			}

		}else if(tmp.find("front") != string::npos){
			if(!q.empty()){
				printf("%d\n", q.front());
			}else{
				printf("-1\n");
			}

		}else if(tmp.find("back") != string::npos){
			if(!q.empty()){
				printf("%d\n", q.back());
			}else{
				printf("-1\n");
			}

		}
	}
}