#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;

struct Node{ ll vmin1, vmin2; };

Node merge(Node l, Node r){
	if(r.vmin1 < l.vmin1){
		if(r.vmin2 < l.vmin1)
			return r;
		return {r.vmin1, l.vmin1};
	}
	else if(r.vmin1 < l.vmin2)
		return {l.vmin1, r.vmin1};
	return {l.vmin1, l.vmin2};
}

Node tree[10][1 << 19];
int TN;

Node rmq(Node *t, int ql, int qr, int idx = 1, int l = 1, int r = TN){
	if(r < ql || qr < l) return {inf, inf};
	if(ql <= l && r <= qr) return t[idx];
	return merge(rmq(t, ql, qr, idx * 2, l, (l + r) / 2),
				 rmq(t, ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void upd(Node *t, int idx, ll val){
	t[idx = (TN + idx - 1)].vmin1 = val;
	for(idx >>= 1; idx; idx >>= 1)
		t[idx] = merge(t[idx * 2], t[idx * 2 + 1]);
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(TN = 1; TN < N; TN <<= 1);
	memset(tree, 0x3f, sizeof(tree));
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		for(int j = 0, cx = x; j < 10; j++, cx /= 10)
			if(cx % 10) upd(tree[j], i, x);
	}

	while(M--){
		int cmd, a, b; scanf("%d %d %d", &cmd, &a, &b);
		if(cmd == 1){
			for(int i = 0, cx = b; i < 10; i++, cx /= 10)
				upd(tree[i], a, (cx % 10) ? b : inf);
		}
		else{
			ll ans = inf;
			for(int i = 0; i < 10; i++){
				Node ret = rmq(tree[i], a, b);
				ans = min(ans, ret.vmin1 + ret.vmin2);
			}
			printf("%lld\n", ans < inf ? ans : -1);
		}
	}
	return 0;
}