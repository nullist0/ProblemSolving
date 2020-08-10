#include <cstdio>
#include <stack>

#define min2(x, y) ((x) > (y) ? (y) : (x))
#define min3(x, y, z) min2(x, min2(y, z))
#define MAX 256

using namespace std;

char str1[MAX], str2[MAX];
int c[MAX+1][MAX+1];

void print_stack(stack<char> *st){
    while(!st -> empty()){
        printf("%c", st -> top());
        st -> pop();
    }
    printf("\n");
}

void trace(int n, int m){
    //Trace
    int current[2] = {n, m};
    stack<char> matched_str1, matched_str2;
    while(current[0] != 0 || current[1] != 0){
        int i = current[0], j = current[1];
        if((i > 0 && j > 0 && str1[i-1] == str2[j-1]) && c[i][j] == c[i-1][j-1]){
            matched_str1.push(str1[i - 1]);
            matched_str2.push(str2[j - 1]);
            current[0]--; current[1]--;
        }
        else if(i > 0 && c[i][j] == c[i-1][j] + 1){
            matched_str1.push(str1[i - 1]);
            matched_str2.push('-');
            current[0]--;
        }
        else if(j > 0){
            matched_str1.push('-');
            matched_str2.push(str2[j - 1]);
            current[1]--;
        }
    }

    print_stack(&matched_str1);
    print_stack(&matched_str2);
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    scanf("%s", str1);
    scanf("%s", str2);

    for(int i = 0; i < n; i++)
        c[i][0] = i;
    for(int j = 0; j < m; j++)
        c[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            c[i][j] = min3(c[i-1][j-1] + !(str1[i-1] == str2[j-1]), c[i-1][j] + 1, c[i][j-1] + 1);
        }
    }

    printf("cost(matching) = %d\n", c[n][m]);
    printf("matched charaters = %d\n", (m + n - c[n][m])/2);

    trace(n, m);

    return 0;
}