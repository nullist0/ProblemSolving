#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

bool isdigit(char t){
    return '0' <= t && t <= '9';
}

int main(){

    char t = 0;
    string inp = "", tmp ="";
    
    int n, c = 0;
    
    scanf("%d", &n);
    
    vector<pair<int, string> > v;
    
    for(int i = 0; i < n; i++){
        cin >> inp;
        
        for(int j = 0; j < inp.length(); j++){
            t = inp.at(j);
            if(isdigit(t)){
                if(tmp.length() == 0 && t == '0' 
                    && ( j<inp.length()-1 && isdigit(inp.at(j+1)))){
                    continue;
                }
                tmp += t;
            }
            else if(tmp.length() > 0){
                v.push_back(make_pair(tmp.length(), tmp));
                c++;
                tmp = "";
            }
        }
        if(tmp.length()>0){
            v.push_back(make_pair(tmp.length(), tmp));
            c++;
            tmp = "";
        }
    }
    sort(v.begin(), v.begin()+c);
    
    for(int i = 0; i < c; i++){
        cout << v[i].second << '\n';
    }
}