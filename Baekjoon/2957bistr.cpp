#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

// vector<pair<int, int> > tree(300001);
int depth[300001];
int nodes[300001], cache[300001];
int n = 0, count = 0, cc = 0;
int gol = 1, gor = 1;

void insert(int value){
// 	count++;
// 	if(value < now){
// 		if(tree[now].first == 0)
// 			tree[now].first = value;
// 		else
// 			insert(value, tree[now].first);
// 	}
// 	else if(now < value){
// 		if(tree[now].second == 0)
// 			tree[now].second = value;
// 		else
// 			insert(value, tree[now].second);
// 	}

	// queue<int> q;

	// q.push(value);

	// while(!q.empty()){
	// 	int t = q.front();
	// 	q.pop();

	// 	if(depth[t] != -1 && nodes[t] < 2){
	// 		nodes[t]++;
	// 		depth[value] = depth[t] + 1;
	// 		count += depth[value];
	// 		return;
	// 	}

	// 	if(t+1 <= n && cache[t+1] != cc && gor){
	// 		q.push(t+1);
	// 		cache[t+1] = cc;

	// 		if(value < t+1 && depth[t+1] != -1)
	// 			gor = 0;
	// 	}
	// 	if(t-1 > 0 && cache[t-1] != cc && gol){
	// 		q.push(t-1);
	// 		cache[t-1] = cc;

	// 		if(value > t-1 && depth[t-1] != -1)
	// 			gol = 0;
	// 	}
	// }

	int top = 0, bottom = 0;
	int less = 0;
	for(int t = value; t <= n; t++){
		if(depth[t] != -1){
			top = t;
			break;
		}
	}

	for(int t = value; t > 0; t--){
		if(depth[t] != -1){
			bottom = t;
			break;
		}
	}
	
	printf("%d %d\n", bottom, top);

	if(top == 0){
		less = bottom;
	}else if(bottom == 0){
		less = top;
	}else{
		if(depth[top] > depth[bottom] && nodes[bottom] < 2)
			less = bottom;
		else if(depth[bottom] > depth[top] && nodes[top] < 2)
			less = top;
	}

	nodes[less]++;
	depth[value] = depth[less] + 1;
	count += depth[value];
}

int main(){
	memset(depth, -1, 300001 * sizeof(int));
	int t = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		if(i == 0){
			// tree[t] = make_pair(0, 0);
			depth[t] = 0;
			nodes[t] = 0;
			count = 0;
			printf("0\n");
		}
		else{
			cc++;
			gor = 1; gol = 1;
			insert(t);
			printf("%d\n", count);
		}
	}
	// printf("------------\n");
	// for(int j = 1; j <= n; j++){
	// 	printf("%d %d %d\n", j, nodes[j], depth[j]);
	// }
	// printf("------------\n");
}