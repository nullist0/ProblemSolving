#include <cstdio>

#define min(x, y) ((x) > (y) ? (y) : (x))
#define MAX 256
#define INF 1e9

int size[MAX];
int cost[MAX+1][MAX+1];

// A_i = size[i] * size[i+1] matrix
// cost[i][j] = A_i ... A_j

void trace(int s, int e){
    if(s == e) printf("A%d", s);
    else if(e-s == 1) printf("(A%dA%d)", s, e);
    else{
        for(int k = s; k <= e; k++){
            if(cost[s][e] == cost[s][k] + cost[k+1][e] + size[s] * size[k+1] * size[e+1]){
                printf("(");

                trace(s, k);
                trace(k+1, e);

                printf(")");
                break;
            }
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i <= n; i++)
        scanf("%d", size + i);

    for(int i = 0; i < n; i++)
        cost[i][i] = 0;

    for(int d = 1; d < n; d++){
        for(int i = 0; i < n - d; i++){
            int j = i + d;
            cost[i][j] = INF;
            for(int k = i; k <= j; k++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k+1][j] + size[i] * size[k+1] * size[j+1]);
            }
        }
    }

    printf("%d\n", cost[0][n-1]);

    trace(0, n-1);
    printf("\n");

    return 0;
}