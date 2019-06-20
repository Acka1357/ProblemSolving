#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Node{
	int idx, par, dir; ll gsum, psum;
	Node(){} Node(int idx, int par, int dir, ll gsum, ll psum): idx(idx), par(par), dir(dir), gsum(gsum), psum(psum){}
};

Node tree[200001];
ll g[200001], p[200001], sum;

Node find(int idx){
	if(tree[idx].par == idx) return tree[idx];
	Node ret = find(tree[idx].par);
	ret.idx = idx;
	ret.dir *= tree[idx].dir;
	return tree[idx] = ret;
}

ll link(int u, int v, int d){
	Node pu = find(u), pv = find(v);
	int ui = pu.par, vi = pv.par;
	sum -= min(pu.gsum, pu.psum) + min(pv.gsum, pv.psum);
	if(ui != vi){
		if(pu.dir * pv.dir * d == 1){
			tree[ui].gsum += pv.gsum;
			tree[ui].psum += pv.psum;
		}
		else{
			tree[ui].gsum += pv.psum;
			tree[ui].psum += pv.gsum;
		}
		tree[vi].par = ui;
		tree[vi].dir = pu.dir * pv.dir * d;
	}
	return sum += min(tree[ui].gsum, tree[ui].psum);
}

ll change_val(int idx, int a, int b){
	ll gv = a - g[idx], pv = b - p[idx];
	g[idx] = a; p[idx] = b;
	Node pi = find(idx);
	sum -= min(pi.gsum, pi.psum);
	if(pi.dir == 1){
		tree[pi.par].gsum += gv;
		tree[pi.par].psum += pv;
	}
	else{
		tree[pi.par].gsum += pv;
		tree[pi.par].psum += gv;
	}
	printf("%d(%d): %lld->%lld(%lld) %lld->%lld(%lld)\n", idx, pi.par, pi.gsum, tree[pi.par].gsum, gv, pi.psum, tree[pi.par].psum, pv);
	return sum += min(tree[pi.par].gsum, tree[pi.par].psum);
}

int main()
{
	int N, D, Q, c, u, v, d; scanf("%d %d", &N, &D);
	for(int i = 1; i <= N; i++){
		scanf("%lld %lld", &g[i], &p[i]);
		tree[i] = Node(i, i, 1, g[i], p[i]);
		sum += min(g[i], p[i]);
	}

	while(D--){
		scanf("%d %d %d", &c, &u, &v);
		link(u, v, c ? -1 : 1);
	}
	printf("%lld\n", sum);

	for(scanf("%d", &Q); Q--;){
		scanf("%d %d %d", &c, &u, &v);
		if(c == 0) printf("%lld\n", link(u, v, 1));
		else if(c == 1) printf("%lld\n", link(u, v, -1));
		else if(c == 2) printf("%lld\n", change_val(u, v, p[u]));
		else printf("%lld\n", change_val(u, g[u], v));
	}

	return 0;
}
