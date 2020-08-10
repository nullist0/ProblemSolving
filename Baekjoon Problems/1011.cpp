#include <cstdio>
#define ll long long
#define sum(x) ((x) * ((x) + 1) / 2)

int go(int n, int k, int r){
	//printf("%d %d %d\n", n, k, r);
	if(r == 1 && (k-1 == 1 || k == 1 || k+1 == 1)) return n+1;
	else if(r < 1) return 0;

	int ret = 0, cache[3] = {0, 0, 0};

	if(k+1 > 0) cache[0] = go(n+1, k+1, r - k - 1);
	if(k > 0) cache[1] = go(n+1, k, r - k);
	if(k-1 > 0) cache[2] = go(n+1, k-1, r - k + 1);
	
	if(cache[0]) ret = ret == 0 ? cache[0] : (ret > cache[0] ? cache[0] : ret);
	if(cache[1]) ret = ret == 0 ? cache[1] : (ret > cache[1] ? cache[1] : ret);
	if(cache[2]) ret = ret == 0 ? cache[2] : (ret > cache[2] ? cache[2] : ret);

	return ret;
}

int main(void){
	ll T, x, y, d, m;
	scanf("%lld", &T);
	while(T--){

		scanf("%lld %lld", &x , &y);
		d = y - x;
		//for(d = 1; d < 40 ; d++){
			//printf("%d ", d);
			for(m = 0; 2 * sum(m) <= d; m++); m--;
			//printf("%d %d %d %d\n", d, m, sum(m), 2 * sum(m));
			if(2 * sum(m) == d) printf("%lld\n", m * 2);
			else if(d - 2 * sum(m) <= m+1) printf("%lld\n", m * 2 + 1);
			else printf("%lld\n", m *2 + 2);
		//}
	}
	return 0;
}
