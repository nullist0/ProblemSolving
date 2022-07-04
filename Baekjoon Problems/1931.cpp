#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int N;

// vector<pair<int, pair<int, int> > > list;
vector<pair<int, int> > list;

int count() {
    int globalEnd = 0;
    int cache = 0;
    int start = -1, end = -1;

    sort(list.begin(), list.end());

    for(int i = 0; i < N; i++) {
        end = list[i].first;
        start = end + list[i].second;

        if(globalEnd <= start) {
            globalEnd = end;
            cache ++;
        }
    }

    return cache;
}

int main(void) {
    int start, end;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &start, &end);

        list.push_back(make_pair(end, start - end));
    }

    printf("%d\n", count());

    return 0;
}