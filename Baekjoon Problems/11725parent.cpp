#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > v(100001);
int parent[100001];
int cache[100001];

int dp(int now){

	for(int i = 0; i < (int)v[now].size(); i++){
		if(v[now][i] != now && cache[v[now][i]] == 0){
			parent[v[now][i]] = now;
			cache[v[now][i]] = 1;
			dp(v[now][i]);
		}
	}
}

int main(){
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int a=0, b=0;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cache[1] = 1;
	dp(1);

	for(int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);
}