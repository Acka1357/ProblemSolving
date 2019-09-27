#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct G{ int l, r, size, gmax; };

struct Range{
	int x, l, r;
	bool operator <(const Range &o)const{
		return l < o.l;
	}
};

G seg[200005];
int par[200005];
Range rng[200005];

int find(int x){
	return x == par[x] ? x : (par[x] = find(par[x]));
}

bool link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return false;
	if(seg[px].r < seg[py].l || seg[py].r < seg[px].l) return false;
	par[py] = px;
	seg[px].l = min(seg[px].l, seg[py].l);
	seg[px].r = max(seg[px].r, seg[py].r);
	seg[px].size += seg[py].size;
	seg[px].gmax = max(seg[px].gmax, seg[py].gmax);
	return true;
}

int main()
{
	int N; scanf("%d %*d", &N);
	for(int i = 1; i <= 200000; i++)
		par[i] = i;
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		if(!seg[x].l) seg[x].l = i;
		seg[x].r = i;
		seg[x].size++;
		seg[x].gmax++;
	}

	for(int i = 1; i <= 200000; i++)
		rng[i] = {i, seg[i].l, seg[i].r};

	sort(rng + 1, rng + 200000 + 1);
	for(int i = 2; i <= 200000; i++)
		link(rng[i - 1].x, rng[i].x);

	int ans = 0;
	for(int i = 1; i <= 200000; i++)
		if(i == par[i]) ans += seg[i].size - seg[i].gmax;
	printf("%d\n", ans);

	return 0;
}