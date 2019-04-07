#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Gold{
	int x, y, w;
	bool operator <(const Gold &o)const{
		return y < o.y;
	}
};

struct Node{
	long long l, r, all, ans;
	void merge(const Node &lc, const Node &rc){
		l = max(lc.l, lc.all + rc.l);
		r = max(rc.r, lc.r + rc.all);
		all = lc.all + rc.all;
		ans = max(lc.r + rc.l , max(max(l, r), max(lc.ans, rc.ans)));
	}
};

int N, NN;
map<int, int> xidx;
Node tree[1 << 13];
Gold gold[3000];

void add_val(int idx, int val){
	idx = NN + idx - 1;
	tree[idx].all = tree[idx].all + val;
	tree[idx].l = tree[idx].r = tree[idx].ans = max(0ll, tree[idx].all);
	for(idx >>= 1; idx; idx >>= 1)
		tree[idx].merge(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	scanf("%d", &N);

	vector<int> xs(N);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &gold[i].x, &gold[i].y, &gold[i].w);
		xs[i] = gold[i].x;
	}

	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

	int X = xs.size();
	for(int i = 0; i < X; i++) xidx[xs[i]] = i + 1;
	for(int i = 0; i < N; i++) gold[i].x = xidx[gold[i].x];

	sort(gold, gold + N);
	for(NN = 1; NN < X; NN <<= 1);

	long long ans = 0;
	for(int i = 0; i < N; i++){
		memset(tree, 0, sizeof(tree));
		if(i && gold[i].y == gold[i - 1].y) continue;
		for(int j = i; j < N; j++){
			add_val(gold[j].x, gold[j].w);
			if(gold[j].y != gold[j + 1].y) ans = max(ans, tree[1].ans);
		}
	}

	printf("%lld\n", ans);
	return 0;
}