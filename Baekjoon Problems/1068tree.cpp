#include <cstdio>
#include <vector>

using namespace std;

int n = 0, head = 0, ban = 0, count = 0;
vector<vector<int> > tree(51);

void order(int now){

	if(now >= n || now == ban){
		return;
	}

	int tmp = 0;
	int res = 0;

	int s = tree[now].size();

	if(s == 0 && head == now)
		return;

	if(s == 0 || s == 1 && tree[now][0] == ban){
		count++;
	}
	else{
		for(int i = 0; i < tree[now].size(); i++){
			tmp = tree[now][i];
			if(tmp != ban)
				order(tmp);
		}
	}
}

int main(){
	int t = 0;

	scanf("%d", &n);

	if(n > 0){

		for(int i = 0; i < n; i++){
			scanf("%d", &t);

			if(t != -1)
				tree[t].push_back(i);
			else
				head = i;
		}

		scanf("%d", &ban);

		order(head);
	}
	printf("%d\n", count);
}