#include <cstdio>

long long prod(long long A, long long B, long long C) {
    if(B == 0) return 1;
    if(B == 1) return A % C;
    if(B == 2) return ((A % C) * (A % C)) % C;

    long long power = prod(A, B/2, C);

    return (prod(power, 2, C) * prod(A, B - (B/2) * 2, C)) % C;
}

int main(void) {
    long long A, B, C;

    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld\n", prod(A, B, C));

    return 0;
}