#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll NINF = 0xbfbfbfbfbfbfbfbf;

ll tree[1 << 18];
int N, D, NN, a[100001];

ll range_max(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(qr < l || r < ql) return NINF;
	if(ql <= l && r <= qr) return tree[idx];
	return max(range_max(ql, qr, l, (l + r) / 2, idx * 2),
			   range_max(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1));
}

void update_val(int idx, ll val){
	tree[NN + idx - 1] = val;
	for(idx = (NN + idx - 1) / 2; idx; idx >>= 1)
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	memset(tree, 0xbf, sizeof(tree));
	scanf("%d %d", &N, &D);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for(NN = 1; NN < N; NN <<= 1);

	ll ans = NINF;
	for(int i = 1; i <= N; i++){
		update_val(i, max(range_max(max(1, i - D), i) + a[i], (ll)a[i]));
		ans = max(ans, tree[NN + i - 1]);
	}
	printf("%lld\n", ans);

	return 0;
}
