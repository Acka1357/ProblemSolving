#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Crd{
	ll x, y, idx;
	bool operator <(const Crd &o)const{
		return y == o.y ? x < o.x : y < o.y;
	}
};

Crd crd[100001];
int par[100001], size[100001];

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return ;
	par[py] = px;
	size[px] += size[py];
}

int main()
{
	int N, D; scanf("%d %d", &N, &D);
	for(int i = 0, x, y; i < N; i++){
		scanf("%d %d", &x, &y);
		crd[i] = {x + y, x - y, i};
		par[i] = i; size[i] = 1;
	}

	sort(crd, crd + N, [](const Crd &a, const Crd &b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});

	set<Crd> cset;
	for(int l = 0, r = 0; r < N; r++){
		while(crd[l].x < crd[r].x - D)
			cset.erase(crd[l++]);

		auto top = cset.upper_bound({-1, crd[r].y, -1});
		auto mid = cset.lower_bound({-1, crd[r].y, -1});
		auto btm = cset.lower_bound({-1, crd[r].y - D, -1});
		if(top != cset.end() && top->y <= crd[r].y + D) link(crd[r].idx, top->idx);
		if(mid != cset.end() && mid->y <= crd[r].y + D) link(crd[r].idx, mid->idx);
		if(btm != cset.end() && btm->y <= crd[r].y + D) link(crd[r].idx, btm->idx); 
		
		cset.insert(crd[r]);
	}

	int cnt = 0, ans = 0;
	for(int i = 0; i < N; i++)
		if(par[i] == i) cnt++, ans = max(ans, size[i]);

	printf("%d %d\n", cnt, ans);

	return 0;
}
