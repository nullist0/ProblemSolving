#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int in[1001];
int res[1001];
int count = 0;

stack<int> arr, tmp;

void print(){
	stack<int> tmp = arr;
	while(!tmp.empty()){
		printf("%d ", tmp.top());
		tmp.pop();
	}
	printf("\n");
}

int dp(int top, int d){

	while(!arr.empty()){
		if(arr.top() != 0){
			tmp.push(arr.top());
			arr.pop();
			while(tmp.top() * arr.top() >= 0){
				tmp.push(arr.top());
				arr.pop();
			}

			while(!tmp.empty()){
				if(tmp.top() > 0)
					arr.push(tmp.top() - 1);
				else if(tmp.top() < 0)
					arr.push(tmp.top() + 1);
				else
					arr.push(0);
				tmp.pop();
			}
			print();
		}
		else{
			while(!arr.empty() && arr.top() == 0)
				arr.pop();
		}
	}

	// if(top > 0 && d == 1){
	// 	tmp.push(top);
	// 	arr.pop();
	// 	dp(arr.top(), d);
	// }
	// else if(top < 0 && d == -1){
	// 	tmp.push(top);
	// 	arr.pop();
	// 	dp(arr.top(), d);
	// }
	// else if((top <= 0 && d == 1) || (top >= 0 && d == -1)){
	// 	while(!tmp.empty()){
	// 		arr.push(tmp.top() - d);
	// 		tmp.pop();
	// 	}
	// 	count++;

	// 	while(!arr.empty()){
	// 		printf("%d ",arr.top());
	// 		arr.pop();
	// 	}

	// 	printf("\n");
	// }
}

int main(){
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int t = 0;
		scanf("%d", &t);

		in[i] = t;
	}

	for(int i = 0; i < n; i++){
		int t = 0;
		scanf("%d", &t);

		arr.push(in[i] - t);
	}

	dp(arr.top(), arr.top() > 0 ? 1 : -1);

	printf("%d\n", count);
}