#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
	deque<int> d;

	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		string s;

		cin >> s;
		if(s == "push_front"){
			int t = 0;
			cin >> t;
			d.push_front(t);
		}
		else if(s == "push_back"){
			int t = 0;
			cin >> t;
			d.push_back(t);
		}
		else if(s == "pop_front"){
			if(d.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if(s == "pop_back"){
			if(d.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if(s == "size")
			cout << d.size() << endl;
		else if(s == "empty")
			printf("%d\n", d.empty());
		else if(s == "front"){
			if(d.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", d.front());
			}
		}else if(s == "back"){
			if(d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.back());
		}
	}
}