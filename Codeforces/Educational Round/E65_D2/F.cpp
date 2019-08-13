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

const ll mod = 1000000007;

struct Node{
	int cnt; ll sum;
	Node(int cnt = 0, ll sum = 0ll): cnt(cnt), sum(sum){};
};

struct Num{
	ll num, idx;
	bool operator <(const Num &o)const{
		return num > o.num;
	}
};

ll N;
Num a[500002];
Node tree[500002];

void add(int idx, ll an){
	while(idx <= N){
		tree[idx].cnt++;
		tree[idx].sum = (tree[idx].sum + an) % mod;
		idx += (idx & -idx);
	}
}

Node cum(int idx){
	Node ret(0, 0);
	while(idx > 0){
		ret.cnt += tree[idx].cnt;
		ret.sum += tree[idx].sum;
		idx -= (idx & -idx);
	}
	ret.sum %= mod;
	return ret;
}

Node range_q(int l, int r){
	Node rn = cum(r);
	Node ln = cum(l - 1);
	return Node(rn.cnt - ln.cnt, (rn.sum - ln.sum + mod) % mod);
}

int main()
{
	scanf("%lld", &N);
	for(int i = 1; i <= N; i++){
		scanf("%lld", &a[i].num);
		a[i].idx = i;
	}
	sort(a + 1, a + N + 1);

	ll ans = 0;
	for(int i = 1; i <= N; i++){
		Node l = cum(a[i].idx);
		Node r = range_q(a[i].idx, N);
		ll L = a[i].idx, R = N - a[i].idx + 1;
		ll ls = ((a[i].idx * (a[i].idx + 1) / 2) + l.sum) % mod;
		ll rs = (((N * (N + 1) / 2) % mod) - ((a[i].idx * (a[i].idx - 1) / 2) % mod) - ((((N * r.cnt) % mod) - r.sum + r.cnt + mod) % mod) + 2 * mod) % mod;
		// printf("%lld(%d): %lld %lld\n", a[i].num, a[i].idx, ls, rs);
		ll d = (((L * rs) % mod) - ((R * ls) % mod) + ((L * R) % mod) + mod) % mod;
		ans = (ans + d * a[i].num) % mod;
		add(a[i].idx, a[i].idx);
	}
	printf("%lld\n", ans);

	return 0;
}
