#include <cstdio>
#define print(a, b, _s, ss) if(a <= _s && _s <= b) printf("%s\n", #ss);

int main(void){
	int s;
	scanf("%d", &s);
	print(90, 100, s, A);
	print(80, 89, s, B);
	print(70, 79, s, C);
	print(60, 69, s, D);
	print(0, 59, s, F);
	return 0;
}
