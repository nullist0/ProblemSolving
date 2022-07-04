#include <cstdio>
#include <stack>

using namespace std;


int main(void) {
    int N;

    scanf("%d", &N);

    int NGE[N];
    int arr[N];

    stack<int> cache;

    for(int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }

    for(int i = N-1; i >= 0; i--) {
        while(!cache.empty() && arr[i] >= cache.top()) {
            cache.pop();
        }

        if(cache.empty()) {
            NGE[i] = -1;
            cache.push(arr[i]);
        } else {
            NGE[i] = cache.top();
            cache.push(arr[i]);
        }
    }

    for(int i = 0; i < N; i++) {
        printf("%d ", NGE[i]);
    }
    printf("\n");

    return 0;
}