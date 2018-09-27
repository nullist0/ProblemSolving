#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
int cache[501];
string roads[501] = {""};
vector<pair<int, int> > rules;
vector<vector<int> > link(501);

void bfs()
{
	for(int i = 0; i < n; i++){
		cache[i] = i;
	}

	queue<pair<string, char> > q;
	q.push(make_pair("", 'A'));
	q.push(make_pair("", 'B'));

	while(!q.empty()){
		string current = q.front().first;
		char next = q.front().second;
		q.pop();

		q.push(make_pair(current+next, 'A'));
		q.push(make_pair(current+next, 'B'));
	}
}

int main(void)
{
	int A, B;

	scanf("%d", &n);

	for(int k = 0; k < n; k++){
		scanf("%d %d", &A, &B);
		rules.push_back(make_pair(A-1, B-1));
	}
	return 0;
}