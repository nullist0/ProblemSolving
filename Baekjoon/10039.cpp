#include <cstdio>

int main(void){
    int n[5], total = 0;

    for(int i = 0; i < 5; i++){
        scanf("%d", n + i);
        if(n[i] < 40) n[i] = 40;

        total += n[i];
    }

    printf("%d\n", total / 5);

    return 0;
}