#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const double eps = 1e-13;
const double PI = acos(0.0) * 2.0;

struct Point{
	long long x, y;
	Point(){};
	Point(long long x, long long y): x(x), y(y){}
	long long operator * (const Point &o)const{
		return (x * o.x) + (y * o.y);
	}
	Point operator - (const Point &o)const{
		return Point(x - o.x, y - o.y);
	}
	long long sqlen(){ return x * x + y * y; }
	double len(){ return sqrt(sqlen()); }
};
 
double angle(Point &l, Point &c, Point &r){
	return acos(min(1.0, max(-1.0, (l * r) / (l.len() * r.len())))) * 180 / PI;
}	

Point o(0, 0);
Point p[300001];

int main()
{
	int N, idx = 0; scanf("%d", &N);
	long long maxl = 0;
	for(int i = 0; i < N; i++){
		scanf("%lld %lld", &p[i].x, &p[i].y);
		if(maxl < p[i].sqlen()){
			maxl = p[i].sqlen();
			idx = i;
		}
	}

	int past = idx;
	double ans = 0;
	for(int i = 1; i <= N; i++)
		if(p[(idx + i) % N].sqlen() == maxl){
			ans = max(ans, angle(p[past], o, p[(idx + i) % N]));
			past = (idx + i) % N;
			printf("%.10lf\n", ans);
		}
	
	printf("%.10lf\n", ans < eps ? 360 : ans);
	return 0;
}
