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
using namespace std;

typedef long long ll;

struct Seg{
	int ty, by, lx, rx;
	Seg(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0): ty(max(y1, y2)), by(min(y1, y2)), lx(min(x1, x2)), rx(max(x1, x2)){}
	bool operator <(const Seg &o)const{
		return ty == o.ty ? by > o.by : ty > o.ty;
	}
};

struct Cand{
	int by, x;
	bool operator <(const Cand &o)const{
		return by < o.by;
	}
};

const int BASE = 5001;

int N, TN = (1 << 14), tree[1 << 15];
Seg seg[5001];

int range_sum(int ql, int qr, int idx = 1, int l = 1, int r = TN){
	if(ql <= l && r <= qr) return tree[idx];
	if(qr < l || r < ql) return 0;
	return range_sum(ql, qr, idx * 2, l, (l + r) / 2)
			+ range_sum(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

void add_val(int idx, int val){
	tree[idx = (TN + idx - 1)] += val;
	for(idx >>= 1; idx; idx >>= 1)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main()
{
	scanf("%d", &N);
	for(int i = 0, x1, x2, y1, y2; i < N; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		seg[i] = Seg(x1 + BASE, y1 + BASE, x2 + BASE, y2 + BASE);
	}

	sort(seg, seg + N);

	ll ans = 0;
	for(int i = 0; i < N; i++){
		if(seg[i].by != seg[i].ty) continue;
		// printf("%d: %d %d %d %d\n", i, seg[i].lx, seg[i].rx, seg[i].ty, seg[i].by);
		// memset(tree, 0, sizeof(tree));
		priority_queue<Cand> q;
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			if(j < i && seg[j].by == seg[j].ty) continue;
			if(seg[j].by == seg[j].ty){
				while(!q.empty()){
					if(q.top().by > seg[j].by){
						add_val(q.top().x, -1);
						q.pop();
					}
					else break;
				}
				ll cnt = range_sum(seg[j].lx, seg[j].rx);
				if(cnt > 1) ans += ((cnt - 1) * cnt) / 2;
				// printf("%d: %d %d %d %d - %lld\n", j, seg[j].lx, seg[j].rx, seg[j].ty, seg[j].by, cnt);
			}
			else{
				if(seg[j].by <= seg[i].ty && seg[i].ty <= seg[j].ty
					&& seg[i].lx <= seg[j].lx && seg[j].lx <= seg[i].rx){
					add_val(seg[j].lx, 1);
					q.push({seg[j].by, seg[j].lx});
				}
			}
		}
		while(!q.empty()){
			add_val(q.top().x, -1);
			q.pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}
