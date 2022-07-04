#include <cstdio>
#include <algorithm>

using namespace std;

int count_target(int *arr, int size, int target) {
    int lower = 0, upper = size - 1;
    {
        int low = 0, high = size - 1, mid;

        while((mid = (low + high) / 2) != low) {
            if(arr[mid] <= target) {
                low = mid;
            } else if(arr[mid] > target) {
                high = mid;
            }
        }
        upper = high;
    }

    {
        int low = 0, high = size - 1, mid;

        while((mid = (low + high) / 2) != low) {
            if(arr[mid] < target) {
                low = mid;
            } else if(arr[mid] >= target) {
                high = mid;
            }
        }
        lower = low;
    }

    if(arr[upper] == target) upper++;
    if(arr[lower] == target) lower--;

    return max(upper - lower - 1, 0);
}

int main(void) {
    int N, M;
    int arr[500000], count[500000], query;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }

    sort(arr, arr + N);

    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        scanf("%d", &query);
        count[i] = count_target(arr, N, query);
    }

    for(int i = 0; i < M; i++){
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}