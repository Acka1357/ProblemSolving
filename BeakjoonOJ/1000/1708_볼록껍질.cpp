#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Crd{
	int x, y;
	bool operator <(const Crd &o)const{
		return x == o.x ? y < o.y : x < o.x;
	}
};

int N;
Crd crd[100000];
vector<Crd> hull;

int calc_ccw(Crd a, Crd b, Crd c){
	long long ccw = (long long)a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
	return ccw ? (ccw < 0 ? -1 : 1) : 0;
}

void make_hull(){
	sort(crd, crd + N);

	hull.resize(N);
	int top = 0;
	for(int i = 0; i < N; i++){
		while(top > 1 && calc_ccw(hull[top - 2], hull[top - 1], crd[i]) <= 0) top--;
		hull[top++] = crd[i];
	}

	// set lower bound of top
	for(int i = N - 2, lb = top; i >= 0; i--){
		while(top > lb && calc_ccw(hull[top - 2], hull[top - 1], crd[i]) <= 0) top--;
		hull[top++] = crd[i];
	}

	// remove crd[0], cause hull[0] == hull[top - 1]
	hull.resize(top - 1);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &crd[i].x, &crd[i].y);

	make_hull();
	printf("%d\n", hull.size());

	return 0;
}