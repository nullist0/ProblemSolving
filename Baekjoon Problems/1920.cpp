//1920 problem
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int n = 0, m = 0, tmp = 0, s = 0, e = 0;

	scanf("%d", &n);

	vector<int> v(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.begin()+n);
	scanf("%d", &m);

	vector<int> res(m);

	for(int i = 0; i < m; i++){

		scanf("%d", &tmp);

		s = 0; e = n-1;

		if(v[0] <= tmp && tmp <= v[n-1]){
			for(int j = 0; j < n; j++){

				if(s == e || s-e == -1 || s-e == 1){
					res[i] = 0;
					if(v[s] == tmp || v[e] == tmp)
						res[i] = 1;
					break;
				}

				if(tmp < v[(s+e)/2])
					e = (s+e)/2;
				else if(tmp == v[(s+e)/2]){
					res[i] = 1;
					break;
				}
				else
					s = (s+e)/2;
			}
		}
		else
			res[i] = 0;
	}

	for(int i = 0; i < m; i++)
		printf("%d\n", res[i]);

	return 0;
}