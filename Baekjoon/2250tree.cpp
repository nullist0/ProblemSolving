#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int count = 1, depthLen = 0;
int parent[10001];
vector<pair<int, int> > tree(10001);
vector<vector<pair<int, int> > > dir(10001);

void inorder(int now, int depth){
	if(tree.size() <= now)
		return;
	int l = tree[now].first, r = tree[now].second;
	
	if(l != -1)
		inorder(l, depth+1);

	dir[depth].push_back(make_pair(count, now));
	count++;

	if(depthLen < depth)
		depthLen = depth;

	if(r != -1)
		inorder(r, depth+1);
}

int main(){
	int n = 0;
	int a = 0, l = 0, r = 0;
	int root = 1;
	int resDepth = 0, resLen = 0;
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &a, &l, &r);
		tree[a] = make_pair(l, r);
	}

	for(int i = 1; i <= n; i++){
		int ll = tree[i].first;
		int rr = tree[i].second;
		if(ll != -1)
			parent[ll] = i;
		if(rr != -1)
			parent[rr] = i;
	}
	for(int i = 1; i <= n; i++){
		if(parent[i] == 0)
			root = i;
	}

	inorder(root, 1);

	for(int i = 1; i <= depthLen; i++){
		int s = dir[i].size();
		int len = 1;
		if(dir[i][s-1].first > dir[i][0].first)
			len = 1 + dir[i][s-1].first - dir[i][0].first;
		else
			len = 1 - dir[i][s-1].first + dir[i][0].first;

		if(len > resLen){
			resLen = len;
			resDepth = i;
		}
	}

	// for(int i = 1; i <= depthLen; i++){
	// 	int s = dir[i].size();
	// 	for(int j = 0; j < s; j++){
	// 		printf("(%d %d)", dir[i][j].first, dir[i][j].second);
	// 	}
	// 	printf("\n");
	// }

	printf("%d %d\n", resDepth, resLen);
	return 0;
}