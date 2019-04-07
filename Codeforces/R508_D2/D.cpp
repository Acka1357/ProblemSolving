#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

long long a[500001], tree[1 << 20], NN = 1;

long long absx(long long x){
	return x < 0? -x : x;
}

int rmq_idx(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	printf("%d %d %d %d %d\n", ql, qr, l, r, idx);
	if(r < ql || qr < l) return -1;
	if(ql <= l && r <= qr) return tree[idx];
	int ali = rmq_idx(ql, qr, l, (l + r) / 2, idx * 2);
	int ari = rmq_idx(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1);
	printf("%d:%d, %d:%d\n", ali, a[ali], ari, a[ari]);
	if(ali < 0) return tree[idx] = ari;
	if(ari < 0) return tree[idx] = ali;
	return tree[idx] = (a[ali] >= a[ari] ? ali : ari);
}

long long min_comb(int l, int r){
	if(l == r) return a[NN + l - 1];

	long long ret = 0;
	printf("%d %d\n", l, r);
	int maxi = rmq_idx(l, r);
	printf("%d\n", maxi);
	if(maxi != l && maxi != r){
		long long lv = min_comb(l, maxi - 1);
		long long rv = min_comb(maxi + 1, r);
		ret = min(-absx(lv) - absx(a[maxi] - rv), -absx(rv) - absx(a[maxi] - lv));
	}
	else if(maxi == l)
		ret = -absx(a[maxi] - min_comb(maxi + 1, r));
	else if(maxi == r)
		ret = -absx(a[maxi] - min_comb(l, maxi - 1));

	return ret;
}

int main()
{
	int N; scanf("%d", &N);
	while(NN < N) NN *= 2;
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	for(int i = 1; i <= N; i++)
		tree[NN + i - 1] = i;
	for(int i = NN - 1; i > 0; i--)
		tree[i] = (a[tree[i * 2] >= a[tree[i * 2 + 1]] ? tree[i * 2] : tree[i * 2 + 1]]);
	
	printf("%lld\n", absx(min_comb(1, N)));	
	return 0;
}
