#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int is_good(char *str){
	stack<char> cs;
	while(*str != '\0'){
		switch(*str){
			case '(':
			case '[':
				cs.push(*str);
				break;
			case ')':
				if(cs.top() == '(')
					cs.pop();
				break;
			case ']':
				if(cs.top() == '[')
					cs.pop();
				break;
		}
	}
	return cs.empty();
}

int is_open_bracket(char ch){
	return ch == '(' || ch == '[';
}

const int sched_prio_to_weight[40] = {
 /* -20 */     88761,     71755,     56483,     46273,     36291,
 /* -15 */     29154,     23254,     18705,     14949,     11916,
 /* -10 */      9548,      7620,      6100,      4904,      3906,
 /*  -5 */      3121,      2501,      1991,      1586,      1277,
 /*   0 */      1024,       820,       655,       526,       423,
 /*   5 */       335,       272,       215,       172,       137,
 /*  10 */       110,        87,        70,        56,        45,
 /*  15 */        36,        29,        23,        18,        15,
};


int calc(char *str){
//(2 + 3 * 3) * 2 + 2 * 3
	while(*str != '\0'){
		switch(*str){
			case '(':
				return 2 * calc(str+1);
			case '[':
				break;
			case ')':
				if(is_open_bracket(*(str+1))){

				}
				break;
			case ']':
				if(is_open_bracket(*(str+1))){
					
				}
				break;
		}
	}
}

int main(void){
	char str[31];

	scanf("%s", str);
	return 0;
}

// string str;
// int n = 0;

// int bracket(int cur, int nu, int res){
// 	if(cur == n-1) return res;

// 	char c1 = str.at(cur), c2 = str.at(cur + 1);

// 	if(c1 == ')'){
// 		if(nu/2 != 0)
// 			return bracket(cur+1, nu/2, res);
// 		else
// 			return bracket(cur+1, 1, res);
// 	}
// 	else if(c1 == ']'){
// 		if(nu/3 != 0)
// 			return bracket(cur+1, nu/3, res);
// 		else
// 			return bracket(cur+1, 1, res);
// 	}
// 	else{
// 		if(c1 == '('){
// 			if(c2 == ')')
// 				return bracket(cur+1, nu * 2, res + nu*2);
// 			return bracket(cur+1, nu * 2, res);
// 		}else if(c1 == '['){
// 			if(c2 == ']')
// 				return bracket(cur+1, nu * 3, res + nu*3);
// 			return bracket(cur+1, nu * 3, res);
// 		}
// 	}
// }

// int main(){
// 	char t = -1;
// 	int l = 0;
// 	stack<char> s, res;

// 	cin >> str;

// 	n = str.length();

// 	s.push(str.at(0));

// 	for(int i = 1; i < str.length(); i++){
// 		t = str.at(i);
// 		if(t == ']' && s.top() == '['){
// 			s.pop();
// 		}
// 		else if(t == ')' && s.top() == '('){
// 			s.pop();
// 		}
// 		else{
// 			s.push(t);
// 		}
// 	}

// 	if(s.empty())
// 		printf("%d\n", bracket(0, 1, 0));
// 	else
// 		printf("0\n");
// }