#include <cstdio>
#include <iostream>

#define MOD 1000000

using namespace std;

int password[5001];
int solve[5001];

int main(void){
	string input;
	char cache;
	int n;

	cin >> input;
	n = input.size();

	for(int i = 0; i < n; i++)
		password[i] = input.at(i) - '0';

	solve[0] = 1;
	for(int i = 1; i < n; i++){
		solve[i] = solve[i-1];
		if(i == 1){
			if(password[i-1] == 1)
				solve[i] += 1;
			else if(password[i-1] == 2 && password[i]<= 7)
				solve[i] += 1;
		}
		else{
			if(password[i-1] == 1)
				solve[i] += solve[i-2];
			else if(password[i-1] == 2 && password[i]<= 6)
				solve[i] += solve[i-2];
		}
		solve[i] %= MOD;
	}

	printf("%d\n", solve[n-1]);

	return 0;
}