#include <cstdio>

int a[500001], tree[1 << 20], TN;

void range_xor(int ql, int qr, int v, int idx = 1, int l = 1, int r = TN){
	if(ql <= l && r <= qr){
		tree[idx] ^= v;
		return ;
	}
	if(r < ql || qr < l) return ;
	range_xor(ql, qr, v, idx * 2, l, (l + r) / 2);
	range_xor(ql, qr, v, idx * 2 + 1, (l + r) / 2 + 1, r);
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	for(TN = 1; TN < N; TN <<= 1);

	int Q, t, l, r, v;
	for(scanf("%d", &Q); Q--;){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d %d", &l, &r, &v);
			range_xor(l + 1, r + 1, v);
		}
		else{
			scanf("%d", &v);
			int ans = a[v + 1];
			for(int i = TN + v; i; i >>= 1)
				ans ^= tree[i];
			printf("%d\n", ans);
		}
	}

	return 0;
}