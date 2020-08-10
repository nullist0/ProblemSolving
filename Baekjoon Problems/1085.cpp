#include <cstdio>
int main(void){
	int x, y, w, h, mx, my;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	mx = w - x > x ? x : w - x;
	my = h - y > y ? y : h - y;
	printf("%d\n", mx > my ? my : mx);
	return 0;
}
