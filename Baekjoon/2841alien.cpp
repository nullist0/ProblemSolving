#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main(){
	int n = 0, m = 0;
	int count = 0;
	int ncount = 0;
	int tstring = 0, tplet = 0;
	scanf("%d %d", &n, &m);

	vector<stack<int> > splet(7);

	for(int i = 0; i < n; i++){

		scanf("%d %d", &tstring, &tplet);

		if(splet[tstring].empty()){
			splet[tstring].push(tplet);
			ncount++;
		}else if(tplet > splet[tstring].top()){
			splet[tstring].push(tplet);
			ncount++;
		}else if(tplet < splet[tstring].top()){
			while(!splet[tstring].empty() && 
					tplet < splet[tstring].top()){
				splet[tstring].pop();
				ncount++;
			}
			if(splet[tstring].empty() || tplet > splet[tstring].top()){
				splet[tstring].push(tplet);
				ncount++;
			}
		}
	}

	printf("%d\n", ncount);
}