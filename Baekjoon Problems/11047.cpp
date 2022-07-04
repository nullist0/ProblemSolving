#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int coin[10];

int leastNumOfCoin() {
    int num = 0;
    int maxNum;
    int value = K;
    for(int i = N-1; i >= 0; i--) {
        maxNum = value / coin[i];
        num += maxNum;
        value -= maxNum * coin[i];

        if(value == 0) break;
    }

    return num;
}

int main(void) {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) {
        scanf("%d", coin + i);
    }

    printf("%d\n", leastNumOfCoin());

    return 0;
}