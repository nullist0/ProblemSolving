#include <cstdio>
#include <cstring>
#include <cstdlib>

char expr[51];

int calc(char *p) {
    if(p == NULL) return 0;
    char *tok = strtok(p, "+-");
    int sum = 0;

    while(tok != NULL) {
        sum += atoi(tok);
        tok = strtok(NULL, "+-");
    }

    return sum;
}

int main(void) {
    char *plus = NULL, *minus = NULL;
    int len;

    scanf("%s", expr);

    len = strlen(expr);

    plus = expr;
    for(char *p = expr; *p != '\0'; p++) {
        if(*p == '-') {
            *p = '\0';
            minus = p + 1;
            break;
        }
    }

    printf("%d\n", calc(plus) - calc(minus));

    return 0;
}