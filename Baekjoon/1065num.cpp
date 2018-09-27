#include <stdio.h>

int han(int i){
    if(i < 100) return 1;

    int d, s = i;
    d = ((i/10)%10) - i%10;
    i /= 10;
    while(i >= 10){
        if(d != ((i/10)%10 - i%10)) return 0;

        i /= 10;
    }
    return 1;
}

int main()
{
    int n, i = 1, res = 0;
    scanf("%d", &n);

    while(i <= n){

        res += han(i);

        i++;
    }

    printf("%d\n", res);

    return 0;
}