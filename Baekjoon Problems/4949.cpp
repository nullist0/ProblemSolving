#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>

using namespace std;

int check_bracket(char* str) {
    stack<char> s;
    int len = strlen(str);
    char cache;

    for(int i = 0; i < len; i++) {
        if(str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            if(s.empty()) return 0;

            cache = s.top();
            if(cache == '(') {
                s.pop();
            } else {
                return 0;
            }
        } else if(str[i] == ']') {
            if(s.empty()) return 0;

            cache = s.top();
            if(cache == '[') {
                s.pop();
            } else {
                return 0;
            }
        }
    }

    return s.empty();
}


int main(void) {
    char input[103] = {0, };

    fgets(input, sizeof(input), stdin);

    while(strcmp(input, ".\n") != 0) {
        printf("%s\n", check_bracket(input) ? "yes": "no");

        fgets(input, sizeof(input), stdin);
    }
    return 0;
}