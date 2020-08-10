#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

stack<int> calc, st;
char s[31], *s_p = s;

void parenthesis();
void calculate();
int check(char *);

void parenthesis(){
	int x;
	s_p++;
	if(*s_p == '(' || *s_p == '['){
		calculate();
		x = calc.top();
		calc.pop();
		calc.push(x * (*s_p == ')' ? 2 : 3));
	}
	else if(*s_p == ')' || *s_p == ']'){
		if(*(s_p-1) == '(' || *s_p == ')'){
			calc.push(2);
		}
		else if(*(s_p-1) == '[' || *s_p == ']'){
			calc.push(3);
		}
	}
}

void calculate(){
	int n1, n2;
	parenthesis();
	s_p++;
	while(*s_p == '(' || *s_p == '['){
		parenthesis();
		s_p++;
		n2 = calc.top(); calc.pop();
		n1 = calc.top(); calc.pop();
		calc.push(n1+n2);
	}
}

int check(char *p){
	while(*p){
		switch (*p)
		{
		case '(': case '[':
			st.push(*p);
			break;
		case ')':
			if(!st.empty() && st.top() == '(') st.pop();
			else return 0;
			break;
		case ']':
			if(!st.empty() && st.top() == '[') st.pop();
			else return 0;
			break;
		default:
			break;
		}
		p++;
	}
	return st.empty();
}

int main(void){
	scanf("%s", s);
	s_p = s;

	if(!check(s)){
		printf("0\n");
		return 0;
	}
	calculate();
	printf("%d\n", calc.top());

	return 0;
}