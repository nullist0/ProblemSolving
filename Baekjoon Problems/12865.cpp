#include <cstdio>
#include <algorithm>

using namespace std;

int N, K, W[100], V[100];

long long knapsack() {
    long long bag[N][K+1];

    // bag[n][w] = bag[n-1][w-w[n]] + V[n] or bag[n-1][w]
    for(int n = 0; n < N; n++) {
        for(int w = 0; w <= K; w++) {
            if(n == 0) {
                bag[0][w] = W[0] <= w ? V[0] : 0;
            } else {
                bag[n][w] = max(w-W[n] >= 0 ? bag[n-1][w-W[n]] + V[n] : 0, bag[n-1][w]);
            }
        }
    }

    return bag[N-1][K];
}

int main(void) {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", W + i, V + i);
    }

    printf("%lld\n", knapsack());

    return 0;
}