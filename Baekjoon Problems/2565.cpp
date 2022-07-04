#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pos[501];

int LIS() {
    int localLIS[501];
    int lis = 1;
    
    for(int i = 0; i < 501; i++) {
        if(pos[i] == 0){
            localLIS[i] = 0;
            continue;
        }

        localLIS[i] = 1;

        for(int j = 0; j < i; j++) {
            if(pos[j] == 0) continue;

            if(pos[j] < pos[i]) {
                localLIS[i] = max(localLIS[j] + 1, localLIS[i]);
            }
        }

        lis = max(lis, localLIS[i]);
    }

    return lis;
}

int main(void) {
    int a, b;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);

        pos[a] = b;
    }

    printf("%d\n", N - LIS());

    return 0;
}