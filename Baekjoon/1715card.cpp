#include <queue>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	priority_queue<int, vector<int>, greater<int> > q;

	int n = 0, t = 0;
	int res = 0;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> t;

		q.push(t);
	}

	while(!q.empty()){
		t = 0;
		if(q.size() >= 2){
			t += q.top();
			q.pop();
			t += q.top();
			q.pop();

			res += t;

			q.push(t);
		}else{
			t = q.top();
			q.pop();
		}
	}

	cout << res << endl;
}