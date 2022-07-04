#include <queue>
#include <cstdio>

using namespace std;

int main(void) {
    int N;
    queue<int> card;

    scanf("%d", &N);

    for(int i = 1; i < N+1; i++) {
        card.push(i);
    }

    while(card.size() > 1) {
        card.pop();
        card.push(card.front());
        card.pop();
    }

    printf("%d\n", card.front());

    return 0;
}