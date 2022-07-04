#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int find(vector<int> vect, int x) {
    int low = 0, high = vect.size();
    int mid = 0;

    while (high != low) {
        mid = (low + high) / 2;
        
        if (x < vect[mid]) high = mid;
        else if (vect[mid] < x) low = mid;
        else return mid;
    }
    return high;
}

int main(void) {
    int cache;
    int N;
    vector<int> sorted;
    vector<int> single;
    vector<int> origin;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &cache);
        origin.push_back(cache);
        sorted.push_back(cache);
    }

    sort(sorted.begin(), sorted.end());

    single.push_back(sorted[0]);
    for (int i = 1; i < N; i++) {
        if (single.back() == sorted[i]) continue;
        single.push_back(sorted[i]);
    }

    for(int i = 0; i < N; i++) {
        printf("%d ", find(single, origin[i]));
    }
    printf("\n");

    return 0;
}