#include <cstdio>

using namespace std;

int main(void){
	int R, G, B;
	int ret = 0;
	scanf("%d %d %d", &R, &G, &B);

	ret += R/3; ret += G/3; ret += B/3;
	R = R % 3; G = G % 3; B = B % 3;

	if(R+G+B > 0 && (R+G == 0 || G+B == 0 || R+B == 0)){
		ret += 1;
	}
	else{
		while(R > 0 || G > 0 || B > 0){
			ret += 1;
			R--; G--; B--;
		}
	}

	printf("%d\n", ret);

	return 0;
}