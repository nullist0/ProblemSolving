#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int> > tree(1001);
int n = 0;

int pre[1001], in[1001];

void dp(){

}

int main(){
	int t = 0;
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++){
		scanf("%d", &n);

		for(int j = 0; j < n; j++){
			scanf("%d", pre[j]);
		}
		for(int j = 0; j < n; j++){
			int it = 0;
			scanf("%d", &it);
			in[j] = it;
		}
	}
}