#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    long double value[100000], total;
    int N, K;

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        scanf("%Lf", &value[i]);
    sort(value, value + N);
    total = 0;
    for(int i = K; i < N - K; i++)
        total += value[i];
    // printf("%.2llf\n", (double)((int)(total/(N-2*K) * 100 + 0.5))/100);
    printf("%.2Lf\n", total/(N-2*K) + 0.005);

    total = value[K] * K + value[N-K-1] * K;
    for(int i = K; i < N - K; i++)
        total += value[i];
    // printf("%.2llf\n", (double)((int)(total/N * 100 + 0.5))/100);
    printf("%.2Lf\n", total/N + 0.005);

    return 0;
}