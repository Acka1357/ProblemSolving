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

const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;

struct Seg{
	int in, out;
	bool operator <(const Seg &o)const{
		return in == o.in ? out < o.out : in < o.in;
	}
};

struct Info{
	int out, target; ll d;
	bool operator <(const Info &o)const{
		return out > o.out;
	}
};

Seg a[200000];
int TN, tree[1 << 20];

int range_min(int ql, int qr, int idx = 1, int l = 0, int r = TN - 1){
	if(qr < l || r < ql) return INF;
	if(ql <= l && r <= qr) return tree[idx];
	return min(range_min(ql, qr, idx * 2, l, (l + r) / 2),
			   range_min(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void update(int idx, int val){
	idx += TN;
	tree[idx] = min(tree[idx], val);
	for(idx >>= 1; idx; idx >>= 1)
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	int N; scanf("%d", &N);
	vector<int> xs;
	for(int i = 0; i < N; i++){
		scanf("%d %d", &a[i].out, &a[i].in);
		xs.push_back(a[i].in);
		xs.push_back(a[i].out);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	map<int, int> xidx;
	for(int i = 0; i < xs.size(); i++)
		xidx[xs[i]] = i;

	for(TN = 1; TN < xs.size(); TN <<= 1);

	sort(a, a + N);
	
	memset(tree, 0x3f, sizeof(tree));

	map<int, ll> cnt;
	priority_queue<Info> q;
	cnt[0] = 1;

	for(int i = 0; i < N; i++){
		int target = range_min(0, xidx[a[i].in]);
		if(target == INF) target = 0;

		while(!q.empty()){
			if(q.top().out > a[i].in) break;
			cnt[q.top().target] = (cnt[q.top().target] + q.top().d) % mod;
			q.pop();
		}

		update(xidx[a[i].out], target + a[i].in - a[i].out);
		q.push({a[i].out, target + a[i].in - a[i].out, cnt[target]});
		// printf("%d: [%d, %d] - %d(%lld) : %d\n", i, a[i].in, a[i].out, target, cnt[target], target + a[i].in - a[i].out);
	}

	ll ansx = a[N - 1].out + 1, ans = 0;
	while(!q.empty()){
		// printf("%lld %lld %lld\n", q.top().out, q.top().target, q.top().d);
		ll x = q.top().target + q.top().out;
		if(ansx > x) ansx = x, ans = 0;
		if(ansx == x) ans = (ans + q.top().d) % mod;
		q.pop();
	}
	printf("%lld\n", ans);

	return 0;
}
