#include <cstdio>
#include <stack>
#include <ctime>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min2(x, y) ((x) > (y) ? (y) : (x))
#define min3(x, y, z) min2(x, min2(y, z))
#define MAX 4096

using namespace std;

char str1[MAX], str2[MAX];

int c[MAX+1][MAX+1];

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
}

int main(void){
    int th, t, n, m;
    clock_t t0, t1;
    double cache[2] = {0, 0};
    double elapse[2] = {0, 0};
    double worst[2] = {0, 0};
    scanf("%d %d %d %d", &th, &t, &n, &m);

    for(int tt = 0; tt < t; tt++){
        scanf("%s", str1);
        scanf("%s", str2);

        t0 = clock();
        for(int i = 0; i < n; i++)
            c[i][0] = i;
        for(int j = 0; j < m; j++)
            c[0][j] = j;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                c[i][j] = min3(c[i-1][j-1] + !(str1[i-1] == str2[j-1]), c[i-1][j] + 1, c[i][j-1] + 1);
            }
        }
        t1 = clock();
        if(tt > th)
            elapse[0] += (double)(t1 - t0);

        if(tt > 2 * th)
            worst[0] = max(worst[0], (double)(t1 - t0));

        t0 = clock();
        trace(n, m);
        t1 = clock();
        if(tt > th)
            elapse[1] += (double)(t1 - t0);
        if(tt > 2 * th)
            worst[1] = max(worst[1], (double)(t1 - t0));

        if(elapse[0] < 0 || elapse[1] < 0)
            return printf("OVERFLOW\n");
    }

    printf("average with %d\npart 1: %lf\npart 2: %lf\ntotal: %lf\n", 
                t - th,
                elapse[0] / (t - th), 
                elapse[1] / (t - th),
                (elapse[0] + elapse[1]) / (t-th));

    printf("worst with %d\npart 1: %lf\npart 2: %lf\ntotal: %lf\n", 
                t - th,
                worst[0],
                worst[1],
                worst[0] + worst[1]);

    return 0;
}