#include <cstdio>
#include <stack>

#define min2(x, y) ((x) > (y) ? (y) : (x))
#define min3(x, y, z) min2(x, min2(y, z))
#define MAX 4096

using namespace std;

char str1[MAX], str2[MAX];
int c[MAX+1][MAX+1];

int arithmetic, comparison, assignment;

void trace(int n, int m){
    // printf("Alignment = {\n");
    int current[2] = {n, m};
    assignment += 2;
    while(current[0] != 0 || current[1] != 0){
        comparison += 2;
        int i = current[0], j = current[1];
        assignment += 2;
        if((comparison += 4) || ((i > 0 && j > 0 && str1[i-1] == str2[j-1]) && c[i][j] == c[i-1][j-1])){
            // printf("(%d, %d) with (%d %d)\n", str1[i-1], str2[j-1], i - 1, j - 1);
            current[0]--; current[1]--;
            assignment += 2; arithmetic += 2;
        }
        else if((comparison += 2) || (i > 0 && c[i][j] == c[i-1][j] + 1)){
            current[0]--;
            assignment ++; arithmetic ++;
        }
        else if((comparison += 2) || (j > 0 && c[i][j] == c[i][j-1] + 1)){
            current[1]--;
            assignment ++; arithmetic ++;
        }
    }
    // printf("}\n");
}

int main(void){
    int n, m;
    scanf("%d %d",&n, &m);

    scanf("%s", str1);
    scanf("%s", str2);

    for(int i = ((assignment += 1), 0); 
        ((comparison += 1), i < n); 
        i++, arithmetic++, assignment++)
        c[i][0] = i;
    for(int j = ((assignment += 1), 0); 
        ((comparison += 1), j < m); 
        j++, arithmetic++, assignment++)
        c[0][j] = j;

    for(int i = ((assignment += 1), 1); 
        ((comparison += 1), i <= n); 
        i++, arithmetic++, assignment++){
        for(int j = ((assignment += 1), 1); 
            ((comparison += 1), j <= m); 
            j++, arithmetic++, assignment++){
            c[i][j] = min3(c[i-1][j-1] + !(str1[i-1] == str2[j-1]), c[i-1][j] + 1, c[i][j-1] + 1);
        }
    }
    printf("part1\nassignment: %d\narithmetic: %d\ncomparison: %d\n", 
        assignment, 
        arithmetic, 
        comparison);
    arithmetic = assignment = comparison = 0;
    trace(n, m);
    printf("part2\nassignment: %d\narithmetic: %d\ncomparison: %d\n", 
        assignment, 
        arithmetic, 
        comparison);

    return 0;
}