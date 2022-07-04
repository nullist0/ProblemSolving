#include <cstdio>

#define MOD 1000000007

long long fact(int n) {
    long long f = 1;
    for(int i = 1; i <= n; i++) {
        f = (f * i) % MOD;
    }
    return f;
}

long long prod(long long n, long long k) {
    if(k == 0) return 1;
    if(k == 1) return n % MOD;

    if(k % 2 == 1) return (n * prod(n, k - 1)) % MOD;

    long long p = prod(n, k / 2);
    return (p * p) % MOD;
}

long long inverse(long long n) {
    return prod(n, MOD - 2);
}

long long combi(int n, int k) {
    if(k == 0) return 1;
    if(n == k) return 1;

    long long up = fact(n);
    long long down = inverse((fact(k) * fact(n-k)) % MOD);

    return (up * down) % MOD;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    printf("%lld\n", combi(N, K));

    return 0;
}