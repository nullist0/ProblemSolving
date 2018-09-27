#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int tc = 0, n = 0, m = 0;

	scanf("%d", &tc);

	for(int i = 0; i < tc; i++){
		vector<int> v;
		queue<pair<int, int> > q, tq;
	
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; j++){
			int t = 0;

			scanf("%d", &t);

			q.push(make_pair(j, t));
			v.push_back(t);
		}

		sort(v.begin(), v.end());
		int maxp = v.back();
		int count = 0;
		int l = v.size();
		for(int k = 0;k < l;){
			if(!q.empty()){
				int now = q.front().first;
				int nowp = q.front().second;

				if(nowp == maxp && now == m){
					count++;
					break;
				}else if(nowp == maxp){
					v.pop_back();
					maxp = v.back();
					
					q.pop();
					count++;
					k++;

				}else{
					tq.push(q.front());
					q.pop();
				}
			}
			else if(!tq.empty()){
				int now = tq.front().first;
				int nowp = tq.front().second;

				if(nowp == maxp && now == m){
					count++;
					break;
				}else if(nowp == maxp){
					v.pop_back();
					maxp = v.back();
					
					tq.pop();
					count++;
					k++;	

				}else{
					q.push(tq.front());
					tq.pop();
				}
			}
		}

		printf("%d\n", count);
	}
}