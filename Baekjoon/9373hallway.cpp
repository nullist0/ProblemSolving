#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int> > sensors(1000);

int w;
int n;

double find(){
	double res = 999999;
	int dx, dy, dr;
	int xi, xj, yi, yj, ri, rj;
	for(int i = 0; i < n-1; i++){
		xi = sensors[i].first.first;
		yi = sensors[i].first.second;
		ri = sensors[i].second;

		xj = sensors[i+1].first.first;
		yj = sensors[i+1].first.second;
		rj = sensors[i+1].second;

		if(xi - ri > 0)
			res = min(res, (double)(xi - ri));
		if(w - xi - ri > 0)
			res = min(res, (double)(w - xi - ri));

		dx = xi - xj;
		dy = yi - yj;
		dr = ri + rj;
		res = min(res, sqrt(dx * dx + dy * dy) - dr);
	}
	return res;
}

int main(){
	int t;
	int x, y, r;
	double res = 0;

	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		scanf("%d", &w);
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%d %d %d", &x, &y, &r);
			sensors[j] = make_pair(make_pair(x, y), r);
		}
		sort(sensors.begin(), sensors.begin() + n);

		res = find();
		if(res > 0)
			printf("%lf\n", res/2);
		else
			printf("0\n");
	}

	return 0;
}
