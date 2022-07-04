#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int P[1000];

int leastTime() {
    int maxTime = 0;
    int cache = 0;
    sort(P, P + N);
    
    for(int i = 0; i < N; i++) {
        cache += P[i];
        maxTime += cache;
    }

    return maxTime;
}

int main(void) {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", P + i);
    }

    printf("%d\n", leastTime());

    return 0;
}