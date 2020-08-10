#include <cstdio>
#define MAX 256

int a[MAX], b[MAX], c[2 * MAX];

int main(void){
    int n, m;

    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++) scanf("%d", a + i);
    for(int i = 0; i <= m; i++) scanf("%d", b + i);

    for(int k = 0; k <= n+m; k++){
        for(int i = 0; i <= k; i++){
            c[k] += a[i] * b[k-i];
        }
    }

    printf("RESULT\n");
    for(int k = 0; k <= n + m; k++)
        printf("x^%d\t", k);
    printf("\n");

    for(int k = 0; k <= n + m; k++)
        printf("%d\t", c[k]);
    printf("\n");

    return 0;
}