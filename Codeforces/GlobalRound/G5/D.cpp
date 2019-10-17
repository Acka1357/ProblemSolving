#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

struct A{ 
	int a, idx; 
	bool operator <(const A &o)const{
		return a == o.a ? o.idx > idx : a > o.a;
	}
};

struct Node{
	int d, idx;
};

Node merge(Node &l, Node &r){
	if(l.d < inf) return {l.d, l.idx};
	return {r.d, r.idx};
}

A order[100005];
int a[100005], amin = 1000000001, amax = 0;
int tree[1 << 18], TN;
Node d[1 << 18];

int range_min(int ql, int qr, int idx = 1, int l = 0, int r = TN - 1){
	if(ql <= l && r <= qr) return tree[idx];
	if(r < ql || qr < l) return inf;
	return min(range_min(ql, qr, idx * 2, l, (l + r) / 2),
			   range_min(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void upd(int idx, int val){
	d[TN + idx] = {val, idx};
	for(idx = (TN + idx) / 2; idx; idx >>= 1)
		d[idx] = merge(d[idx * 2], d[idx * 2 + 1]);
}

Node leftmost(int ql, int qr, int idx = 1, int l = 0, int r = TN - 1){
	if(ql <= l && r <= qr) return d[idx];
	if(r < ql || qr < l) return {inf, inf};
	Node lt = leftmost(ql, qr, idx * 2, l, (l + r) / 2);
	if(lt.d < inf) return lt;
	return leftmost(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

int main()
{
	int N; scanf("%d", &N);
	for(TN = 1; TN < N; TN <<= 1);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		amin = min(amin, a[i]);
		amax = max(amax, a[i]);
		tree[TN + i] = a[i];
		order[i] = {a[i], i};
	}
	if(2 * amin >= amax){
		for(int i = 0; i < N; i++)
			printf("-1%c", " \n"[i == N - 1]);
		return 0;
	}

	for(int i = N; i < TN; i++) tree[TN + i] = inf;
	for(int i = TN - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

	memset(d, 0x3f, sizeof(d));

	sort(order, order + N);

	for(int i = 0; i < N; i++){
		int v = order[i].a, idx = order[i].idx;

		Node lm = leftmost(idx + 1, TN - 1);
		if(lm.d < inf){
			int l = idx, r = lm.idx, m, ans = -1;
			while(l <= r){
				m = (l + r) / 2;
				if(2 * range_min(idx, m) < v) r = m - 1;
				else l = m + 1, ans = m;
			}
			if(ans == lm.idx)
				upd(idx, d[TN + lm.idx].d + lm.idx - idx);
			else upd(idx, ans - idx + 1);

			continue;
		}

		if(2 * range_min(idx, TN - 1) < v){
			int l = idx, r = TN - 1, m, ans = -1;
			while(l <= r){
				m = (l + r) / 2;
				if(2 * range_min(idx, m) < v) r = m - 1;
				else l = m + 1, ans = m;
			}
			upd(idx, ans - idx + 1);
			continue;
		}

		lm = leftmost(0, idx - 1);
		if(lm.d == inf) lm.idx = idx - 1;
		int l = 0, r = lm.idx, m, ans = -1;
		while(l <= r){
			m = (l + r) / 2;
			if(2 * range_min(0, m) < v) r = m - 1;
			else l = m + 1, ans = m;
		}

		if(ans == lm.idx)
			upd(idx, d[TN + lm.idx].d + lm.idx + N - idx + (lm.d == inf));
		else upd(idx, ans + N - idx + 1);
	}

	for(int i = 0; i < N; i++)
		printf("%d%c", d[TN + i].d, " \n"[i == N - 1]);

	return 0;
}