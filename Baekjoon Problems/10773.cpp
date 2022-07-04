#include <cstdio>

int K;

int main(void) {
    int total = 0;
    
    {
        int K;
        scanf("%d", &K);

        int stack[K];
        int cache;
        int *stack_ptr = stack;

        while(K--) {
            scanf("%d", &cache);

            if(cache == 0 && stack_ptr - stack > 0) stack_ptr--;
            else *(stack_ptr++) = cache;
        }

        for(int *pp = stack; pp < stack_ptr; pp++) {
            total += *pp;
        }
    }

    printf("%d\n", total);

    return 0;
}