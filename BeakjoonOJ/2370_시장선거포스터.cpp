#include <stdio.h>
#include <algorithm>
using namespace std;

int tree[1 << 16], NN, l[10000], r[10000], xs[20000], xcnt;

int find_idx(int x){
	int li = 0, ri = xcnt - 1, m;
	while(li <= ri){
		m = (li + ri) / 2;
		if(xs[m] < x) li = m + 1;
		else if(xs[m] > x) ri = m - 1;
		else return m + 1;
	}
	return -1;
}

void range_add(int ql, int qr, int idx = 1, int l = 1, int r = NN){
	if(qr < l || r < ql || tree[idx] == r - l + 1) return ;
	if(ql <= l && r <= qr){ tree[idx] = r - l + 1; return ; }
	range_add(ql, qr, idx * 2, l, (l + r ) / 2);
	range_add(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main()
{
	int N, xi = 0; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &l[i], &r[i]);
		xs[xi++] = l[i]; xs[xi++] = r[i];
	}

	sort(xs, xs + xi);

	for(int i = xcnt = 1; i < xi; i++)
		if(xs[i] != xs[xcnt - 1]) xs[xcnt++] = xs[i];

	int ans = 0, pcnt = 0;
	for(NN = 1; NN < xcnt; NN <<= 1);
	for(int i = N - 1; i >= 0; i--){
		range_add(find_idx(l[i]), find_idx(r[i]));
		if(tree[1] != pcnt) ans++;
		pcnt = tree[1];
	}

	printf("%d\n", ans);
	return 0;
}