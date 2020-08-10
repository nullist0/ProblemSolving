#include <cstdio>

int main(void){
    long long n, ret = 0;
    scanf("%lld", &n);

    for(ret = 1; n != 1; ret++){
        if(n % 2 == 1)
            n = n + 1;
        else
            n = n / 2;
    }
    printf("%lld\n", ret-1);

    return 0;
}