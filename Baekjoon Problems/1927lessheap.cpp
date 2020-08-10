#include <queue>
#include <functional>
#include <cstdio>
#include <vector>

using namespace std;

int main(){

	priority_queue<int, vector<int>, greater<int> > q;

	int n = 0, m = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &m);

		if(m == 0){
			if(q.empty())
				printf("0\n");
			else{
				printf("%d\n", q.top());
				q.pop();
			}
		}else{
			q.push(m);
		}
	}

	return 0;
}