#include <cstdio>
#include <cmath>

int main(){
	int n = 0, m = 0;
	int sum = 0, small = -1;
	int in = 0, im = 0;
	float fn = 0.0f, fm = 0.0f;

	scanf("%d %d", &n, &m);

	fn = sqrt(n);
	fm = sqrt(m);

	in = fn / 1 == (int)fn ? fn : fn+1;
	im = fm;

	for(int i = in; i <= im; i++){
		if(i == in)
			small = i * i;
		sum += i * i;
	}

	if(small == -1)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, small);
}