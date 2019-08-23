#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

struct Node{
	int d, p;
	bool operator <(const Node &o)const{
		return p == o.p ? d > o.d : p > o.p;
	}
};

Node node[300005];
int N, TN, tree[1 << 20], a[300005], lm[300005];
ll d[300005];

int find_leftmost(int ql, int qr, int idx = 1, int l = 1, int r = TN){
	if(qr < l || r < ql) return TN + 1;
	if(ql <= l && r <= qr) return tree[idx];
	return min(find_leftmost(ql, qr, idx * 2, l, (l + r) / 2),
			   find_leftmost(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void insert_val(int idx){
	tree[TN + idx - 1] = idx;
	for((idx = (TN + idx - 1)) >>= 1; idx; idx >>= 1)
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		node[i] = {i, a[i]};
	}

	for(TN = 1; TN < N; TN <<= 1);
	memset(tree, 0x3f, sizeof(tree));

	sort(node + 1, node + N + 1);

	for(int i = 1; i <= N; i++){
		lm[node[i].d] = find_leftmost(node[i].d, TN);
		insert_val(node[i].d);
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++){
		ans = max(ans, d[i]);
		int nxt = lm[i];
		if(nxt <= N) d[nxt] = max(d[nxt], ans - a[i] + a[nxt]);
	}
	printf("%lld\n", ans);

	return 0;
}