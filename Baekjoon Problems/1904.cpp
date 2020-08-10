#include <cstdio>

int val[1000001];

int main(void){
    int N;

    scanf("%d", &N);

    val[1] = 1;
    val[2] = 2;

    for(int i = 3; i <= N; i++)
        val[i] = (val[i-2] % 15746 + val[i-1] % 15746) % 15746;
    printf("%d\n", val[N]);
    
    return 0;
}