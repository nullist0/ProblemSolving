#include <cstdio>

int S, K;

int main(void){
    int d, r, sum = 0;
    long long ret = 1;
    scanf("%d %d", &S, &K);
    d = S/K;
    r = S%K;

    while(K--){
        if(r-- > 0)
            ret *= (d + 1);
        else
            ret *= d;
    }

    printf("%lld\n", ret);

    return 0;
}