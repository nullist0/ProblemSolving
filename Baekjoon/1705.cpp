#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int> > rule(500);
vector<string> route(500);

void dp(int s){
	queue<int> q;
	int cup, A, B;
	q.push(s);

	while(!q.empty()){
		cup = q.front(); q.pop();
		A = cup.first; B = cup.second;
		route[s] += "A";
	}
}

int main(void){
	int a, b, N;

	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d %d", &a, &b);
		rule[i] = make_pair(a-1, b-1);
	}

	return 0;
}