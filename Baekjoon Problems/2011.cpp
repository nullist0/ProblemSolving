#include <cstdio>
#include <cstring>

#define MOD 1000000

using namespace std;

char password[5001];
int len;

//TopDown
int dp(int current){
	int ret = 0;
	if(current == len) return 1;
	if(current > len) return 0;
	if(password[current] == '0') return 0;

	int x = password[current], y = password[current + 1];
	ret += dp(current + 1) % MOD;
	if(x == '1' || x == '2')
		ret += dp(current + 2) % MOD;
	return ret;
}

int ret[50001];
//BottomUp
int updp(){
	int len = strlen(password);
	
	if(password[len - 1] != '0')
		ret[len - 1] = 1;
	if(len >= 2){
		ret[len-2] = ret[len-1];
		if(password[len - 2] == '1' || (password[len - 2] == '2' && password[len - 1] <= '6'))
			ret[len - 2]++;
	}
	for(int i = len - 3; i >= 0; i--){
		if(password[i] != '0' && password[i + 1] != '0')
			ret[i] += ret[i + 1];
		if(password[i] == '1' || (password[i] == '2' && password[i+1] <= '6'))
			ret[i] += ret[i + 2] % MOD;
		ret[i] %= MOD;
	}

	for(int i = 0; i < len; i++)
		printf("[%d]", ret[i]);
	printf("\n");
	return ret[0] % MOD;
}

int main(void){
	int ret = 1;

	scanf("%s", password);
	len = strlen(password);

	// printf("%d\n", dp(0) % MOD);
	printf("%d\n", updp() % MOD);
	return 0;
}