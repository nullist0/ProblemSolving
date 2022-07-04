#include <cstdio>

long long P[101];

int main(void) {
    int T, N;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    for(int n = 6; n < 101; n++) {
        P[n] = P[n-1] + P[n-5];
    }

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        printf("%lld\n", P[N]);
    }

    return 0;
}