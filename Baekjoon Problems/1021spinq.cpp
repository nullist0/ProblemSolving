#include <deque>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

deque<int> dq;

int main(){
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	int target[m];
	int count = 0, res = 0;

	for(int i = 0; i < m; i++){
		scanf("%d", &target[i]);
	}

	for(int i = 1; i <= n; i++)
		dq.push_back(i);

	while(count != m){
		if(dq.front() == target[count]){
			count++;
			dq.pop_front();
		}
		else{
			int rr = 0, rl = 0;

			deque<int> tmpl = dq;
			while(tmpl.front() != target[count]){
				int t = tmpl.front();
				tmpl.pop_front();
				tmpl.push_back(t);
				rl++;
			}

			deque<int> tmpr = dq;
			while(tmpr.front() != target[count]){
				int t = tmpr.back();
				tmpr.pop_back();
				tmpr.push_front(t);
				rr++;
			}

			if(rl > rr){
				dq = tmpr;
			}
			else{
				dq = tmpl;
			}
			res += min(rl, rr);
		}
	}

	printf("%d\n", res);
}
// 1 2 3 4 5 6 7 8 9 10
// 10 1 2 3 4 5 6 7 8 9
// 9 10 1 2 3 4 5 6 7 8
// 8 9 10 1 2 3 4 5 6 7
// 7 8 9 10 1 2 3 4 5 6
// pop
// 8 9 10 1 2 3 4 5 6
// 9 10 1 2 3 4 5 6 8
// 10 1 2 3 4 5 6 8 9
// 1 2 3 4 5 6 8 9 10
// 2 3 4 5 6 8 9 10 1
// pop
// 3