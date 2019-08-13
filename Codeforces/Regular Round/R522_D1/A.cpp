#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

struct Point{
	double x, y;
	Point(){} Point(double x, double y):x(x), y(y){};
};

double A, B, C;

double absx(double a){
	return a < 0 ? -a : a;
}

double get_dist(Point a, Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_mandist(Point a, Point b){
	return absx(a.x - b.x) + absx(a.y - b.y);
}

double calc_path(Point s, Point l1, Point l2, Point e){
	return get_mandist(s, l1) + get_dist(l1, l2) + get_mandist(l2, e);
}

Point calc_vp(double x){
	return Point(x, (-A * x - C) / B);
}

Point calc_hp(double y){
	return Point((-B * y - C) / A, y);
}

int main()
{
	scanf("%lf %lf %lf", &A, &B, &C);
	Point lp, rp; scanf("%lf %lf %lf %lf", &lp.x, &lp.y, &rp.x, &rp.y);
	if(lp.x >= rp.x){
		if(lp.x > rp.x) swap(lp, rp);
		else if(lp.y < rp.y) swap(lp, rp);
		else if(lp.x == rp.y) return !printf("0\n");
	}

	Point lv = calc_vp(lp.x);
	Point lh = calc_hp(lp.y);
	Point rv = calc_vp(rp.x);
	Point rh = calc_hp(rp.y);

	double ans = get_mandist(lp, rp);
	ans = min(ans, calc_path(lp, lv, rv, rp));
	ans = min(ans, calc_path(lp, lv, rh, rp));
	ans = min(ans, calc_path(lp, lh, rv, rp));
	ans = min(ans, calc_path(lp, lh, rh, rp));

	printf("%.10lf\n", ans);
	return 0;
}
