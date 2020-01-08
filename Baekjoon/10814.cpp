#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n;
    vector<pair<int, pair<int, string> > > list;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string name;
        int age;

        cin >> age;
        cin >> name;

        list.push_back(make_pair(age, make_pair(i, name)));
    }

    sort(list.begin(), list.end());

    for(int i = 0; i < n; i++){
        printf("%d ", list[i].first);
        cout << list[i].second.second << "\n";
    }

    return 0;
}