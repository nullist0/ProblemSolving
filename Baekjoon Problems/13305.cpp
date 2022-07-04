#include <cstdio>

int N;

long long gas[100000];
long long distance[100000];

long long cost() {
    long long sum = 0;

    int current = 0;

    while(current < N) {
        int dist = 0;
        int edge, next;
        for(edge = current; edge < N - 1; edge++) {
            dist += distance[edge];
            next = edge + 1;
            if(gas[current] > gas[next]) {
                break;
            }
        }
        
        sum += dist * gas[current];
        current = edge + 1;
    }

    return sum;
}

int main(void) {
    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++) {
        scanf("%lld", distance + i);
    }

    for(int i = 0; i < N; i++) {
        scanf("%lld", gas + i);
    }

    printf("%lld\n", cost());

    return 0;
}