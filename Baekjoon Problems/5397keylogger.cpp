#include <stack>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int tc = 0;
	scanf("%d", &tc);	

	stack<char> head, tail;
	
	for(int i = 0; i < tc; i++){
		char t = -1;
		string str = "", res = "";
		cin >> str;

		str += "\n";

		for(int j = 0; j < str.size(); j++){
			t = str.at(j);
			if(t == '<'){
				if(!head.empty()){
					tail.push(head.top());
					head.pop();
				}
			}else if(t == '>'){
				if(!tail.empty()){
					head.push(tail.top());
					tail.pop();
				}
			}else if(t == '-'){
				if(!head.empty())
					head.pop();
			}else{
				if(t != '\n')
					head.push(t);
			}
		}

		while(!head.empty()){
			res += head.top();
			head.pop();
		}

		reverse(res.begin(), res.end());

		while(!tail.empty()){
			res += tail.top();
			tail.pop();
		}

		cout << res << endl;
	}
}

// int main(){
// 	string str = "";
// 	int tc = 0;

// 	scanf("%d", &tc);

// 	for(int i = 0; i < tc; i++){
// 		char t = 0;
// 		char head[1000000] = {};
// 		char tail[1000000] = {};
	
// 		int hl = 0, tl = 0;
// 		cin >> str;

// 		str += "\n";

// 		for(int j = 0; t != '\n'; j++){
// 			t = str.at(j);
// 			//printf("%s : %s\n", head, tail);

// 			if(t == '<'){
// 				if(hl > 0){
// 					hl--;
// 					tail[tl] = head[hl];
// 					head[hl] = 0;
// 					tl++;
// 				}
// 			}else if(t == '>'){
// 				if(tl > 0){
// 					tl--;
// 					head[hl] = tail[tl];
// 					tail[tl] = 0;
// 					hl++;
// 				}
// 			}else if(t == '-'){
// 				hl--;
// 				head[hl] = 0;
// 			}else{
// 				if(t != '\n'){
// 					head[hl] = t;
// 					hl++;
// 				}
// 			}
// 		}

// 		printf("%s", head);
// 		printf("%s\n", tail);
// 	}
// }