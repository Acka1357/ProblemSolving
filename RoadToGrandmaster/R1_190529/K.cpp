#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const int NINF = 0x80808080;

struct Crd{
	int x, y, idx; 
	bool operator <(const Crd &o)const{
		return x < o.x; 
	}
};

int N, M, H, R, Y, YY, t[4][1 << 19], ox[200001], oy[200001];
Crd hotel[100001], rest[100001];
vector<int> xs, ys, hy[200002];
map<int, int> vals[4][200001];

int range_max(int *tree, int qb, int qt, int b = 1, int t = YY, int idx = 1){
	if(qt < b || t < qb) return NINF;
	if(qb <= b && t <= qt) return tree[idx];
	return max(range_max(tree, qb, qt, b, (b + t) / 2, idx * 2),
			range_max(tree, qb, qt, (b + t) / 2 + 1, t, idx * 2 + 1));
}

void update_val(int *tree, int y, int val){
	tree[YY + y - 1] = val;
	for(y = (YY + y - 1) >> 1; y; y >>= 1)
		tree[y] = max(tree[y * 2], tree[y * 2 + 1]);
}

void add_val(int ti, int y, int val){
	vals[ti][y][val]++;
	update_val(t[ti], y, vals[ti][y].rbegin()->first);
}

void del_val(int ti, int y, int val){
	auto it = vals[ti][y].find(val);
	if(--(it->second) == 0) vals[ti][y].erase(it);
	update_val(t[ti], y, vals[ti][y].size() ? vals[ti][y].rbegin()->first : NINF);
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 1; i <= H; i++){
		scanf("%d %d", &hotel[i].x, &hotel[i].y);
		hotel[i].idx = i; 
		xs.push_back(hotel[i].x);
		ys.push_back(hotel[i].y);
	}
	scanf("%d", &R);
	for(int i = 1; i <= R; i++){
		scanf("%d %d", &rest[i].x, &rest[i].y);
		rest[i].idx = i;
		xs.push_back(rest[i].x);
		ys.push_back(rest[i].y);
	}

	sort(xs.begin(), xs.end()); sort(ys.begin(), ys.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	Y = ys.size();
	for(YY = 1; YY < Y; YY <<= 1);

	map<int, int> xm, ym;
	for(int i = 0; i < xs.size(); i++)
		xm[xs[i]] = i + 1, ox[i + 1] = xs[i];
	for(int i = 0; i < ys.size(); i++)
		ym[ys[i]] = i + 1, oy[i + 1] = ys[i];

	memset(t, 0x80, sizeof(t));
	for(int i = 1; i <= H; i++){
		int ix = xm[hotel[i].x], iy = ym[hotel[i].y];
		hy[ix].push_back(iy);
		add_val(1, iy, ox[ix] + oy[iy]);
		add_val(2, iy, ox[ix] - oy[iy]);
	}
	for(int i = 1; i <= R; i++)
		rest[i].x = xm[rest[i].x], rest[i].y = ym[rest[i].y];

	sort(rest + 1, rest + R + 1);

	int mind = 2000000001, ans = -1, hx = 1;
	for(int i = 1; i <= R; i++){
		while(hx <= rest[i].x){
			for(int yv : hy[hx]){
				del_val(1, yv, ox[hx] + oy[yv]);
				del_val(2, yv, ox[hx] - oy[yv]);
				add_val(0, yv, -ox[hx] + oy[yv]);
				add_val(3, yv, -ox[hx] - oy[yv]);
			}
			hx++;
		}

		ll x = ox[rest[i].x], y = oy[rest[i].y];
		ll d1 = x - y + range_max(t[0], rest[i].y, Y);
		ll d2 = -x - y + range_max(t[1], rest[i].y, Y);
		ll d3 = -x + y + range_max(t[2], 1, rest[i].y);
		ll d4 = x + y + range_max(t[3], 1, rest[i].y);
		ll d = max({d1, d2, d3, d4});
		if(mind > d) mind = d, ans = rest[i].idx;
	}
	printf("%d\n%d\n", mind, ans);

	return 0;
}
