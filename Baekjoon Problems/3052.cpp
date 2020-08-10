#include <cstdio>
int mod[42];
int main(void){
	int i, cache, ret = 0;
	for(i = 0; i < 10; i ++){
		scanf("%d", &cache);
		mod[cache%42]++;
	}
	for(i = 0; i < 42; i++)
		ret += (mod[i] > 0);
	printf("%d\n", ret);
	return 0;
}
