#include <cstdio>
#include <queue>
int n, k, l;
char str[10001];
int map[10001][10001];
int cache[10001];

using namespace std;

int simpleCheckPalindrome(int start, int end){
    int w = end - start, u;
    int minU = (k * w)/(2 * l) + ((k * w) % (2 * l) != 0);
    if(w == 1 || 2 * minU > w) return 0;

    for(u = 0; u < minU; u++){
        if(str[start + u] != str[end - u - 1])
            return 0;
    }

    return 1;
}

int bruteforce(int start, int end){
    int w = end - start, u;
    int minU = (k * w)/(2 * l) + ((k * w) % (2 * l) != 0);
    if(w == 1 || 2 * minU > w) return 0;

    for(u = 0; u < minU; u++){
        if(str[start + u] != str[end - u - 1]){
            int preCache, postCache;

            for(int sep = start + 2; sep <= end - 2; sep++){
                if(str[sep] == str[end - 1]){
                    if((preCache = bruteforce(start, sep)) && (postCache = bruteforce(sep, end))) 
                        return preCache + postCache;
                }
            }
            return 0;
        }
    }

    return 1;
}

int graph(){
    if(n == 1) return 0;
    // build map for u
    map[n-2][n-1] = (str[n-2] == str[n-1]);
    for(int s = 0; s < n-2; s++){
        map[s][s+1] = (str[s] == str[s+1]);
        map[s][s+2] = (str[s] == str[s+2]);
    }

    for(int l = 3; l < n; l++){
        for(int s = 0; s < n-l; s++){
            if(str[s] == str[s+l])
                map[s][s+l] = map[s+1][s+l-1] + 1;
            else
                map[s][s+l] = 0;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }

    int flag = 0;
    for(int s = 0; s <= n; s++){
        if(map[s][n-1]){
            flag = 1;
            break;
        }
    }
    if(!flag) return 0;

    queue<pair<int, int>> q;
    int p, ret, call = 0;
    int w, u;
    q.push(make_pair(1, 0));
    cache[0] = 1;

    while(!q.empty()){
        call++;
        ret = q.front().first;
        p = q.front().second;
        q.pop();
        u = map[p][n-1];
        w = n - p;

        if(k * w <= 2 * u * l){
            return ret;
        }

        for(int ep = n-2; ep > p; ep--){
            if(cache[ep+1]) continue;
            u = map[p][ep];
            w = ep - p + 1;
            if(k * w <= 2 * u * l){
                cache[ep+1] = 1;
                q.push(make_pair(ret+1, ep+1));
            }
        }
    }
    return 0;
}

int main(void){
    scanf("%d %d %d", &n, &k, &l);
    scanf("%s", str);
    //theta = k/l <= 2 u / w =>>>> k w <= 2 u l
    printf("%d\n", graph());
    return 0;
}