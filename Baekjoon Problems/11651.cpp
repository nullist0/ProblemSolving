#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(void){
    vector<pair<int, int> > points;
    int n, y, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        points.push_back(make_pair(y, x));
    }

    sort(points.begin(), points.end());

    for(int i = 0; i < n; i++){
        printf("%d %d\n", points[i].second, points[i].first);
    }
    return 0;
}