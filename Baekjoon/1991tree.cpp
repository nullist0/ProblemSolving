#include <vector>
#include <cstdio>

using namespace std;

vector<pair<int, int> > v(26);

void preorder(int now){
	printf("%c",(char)(now+'A'));
	if(v[now].first >= 0)
		preorder(v[now].first);
	if(v[now].second >= 0)
		preorder(v[now].second);
}

void inorder(int now){
	if(v[now].first >= 0)
		inorder(v[now].first);
	printf("%c",(char)(now+'A'));
	if(v[now].second >= 0)
		inorder(v[now].second);
}

void postorder(int now){
	if(v[now].first >= 0)
		postorder(v[now].first);
	if(v[now].second >= 0)
		postorder(v[now].second);
	printf("%c",(char)(now+'A'));
}

int main(){
	char c[3] = {0, };
	int n = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %c %c %c", &c[0], &c[1], &c[2]);
		v[(int)(c[0] - 'A')] = make_pair(
			 (int)(c[1] - 'A'), (int)(c[2] - 'A'));
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
}