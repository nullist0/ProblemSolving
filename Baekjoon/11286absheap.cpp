#include <queue>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Compare{
public:
	bool operator() (int f, int b){
		int rf = f < 0 ? -1 * f : f;
		int rb = b < 0 ? -1 * b : b;
		if(rf != rb)
			return rf > rb;
		else
			return f > b;
	}
};

int main(){

	priority_queue<int, vector<int>, Compare > q;

	int n = 0, t = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		if(t == 0){
			if(!q.empty()){
				cout << q.top() << endl;
				q.pop();
			}else{
				cout << "0" << endl;
			}
		}else{
			q.push(t);
		}
	}

	return 0;
}