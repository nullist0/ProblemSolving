#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int d(int n){
	return (n*2)%10000;
}

int s(int n){
	return (n == 0) ? 9999 : n-1;
}

int l(int n){
	return (n * 10 + n/1000) % 10000;
}

int r(int n){
	return (n%10)*1000 + (n/10);
}

long long res = 0;
int t = 0;

int cache[10001];

long long bfs(int i, int st, int e){
	queue<long long> q;
	q.push(st);

	while(!q.empty()){
		t = q.front()%10000;
		res = q.front()/10000;

		// printf("%lld %d\n", res, t);

		if(t == e){
			return res;
		}

		q.pop();

		if(cache[t] != i){
			cache[t] = i;
			
			q.push((res*10 + 1)*10000 + d(t));
			q.push((res*10 + 2)*10000 + s(t));
			q.push((res*10 + 3)*10000 + l(t));
			q.push((res*10 + 4)*10000 + r(t));
		}
	}
	return 0;
}

int main(){
	int n = 0, s = 0, e = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &s, &e);

		long long ll = bfs(i+1, s, e);
		int t = 0;
		string s = "";
		while(ll != 0){
			t = ll % 10;
			if(t	 == 1){
				s += "D";
			}else if(t == 2){
				s += "S";
			}else if(t == 3){
				s += "L";
			}else{
				s += "R";
			}
			ll = ll/10;
		}

		reverse(s.begin(), s.end());

		cout << s << endl;
	}
	return 0;
}

//37
//74
//