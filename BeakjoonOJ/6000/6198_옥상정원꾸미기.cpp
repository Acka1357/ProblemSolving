#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct B{
	int idx, h;
	bool operator <(const B &o)const{
		return h == o.h ? idx > o.idx : h > o.h;
	}
};

B b[80001];
int tree[1 << 18], N, NN, INF = 0x3f3f3f3f;

int range_min(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(r < ql || qr < l) return INF;
	if(ql <= l && r <= qr) return tree[idx];
	return min(range_min(ql, qr, l, (l + r) / 2, idx * 2),
				range_min(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1));
}

void set_val(int idx, int v){
	tree[idx = NN + idx - 1] = v;
	for(idx >>= 1; idx; idx >>= 1)
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &b[i].h);
		b[i].idx = i;
	}

	sort(b + 1, b + N + 1);

	for(NN = 1; NN < N; NN <<= 1);
	memset(tree, 0x3f, sizeof(tree));

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		int ni = range_min(b[i].idx, N);
		ans += min(N + 1, ni) - b[i].idx - 1;
		set_val(b[i].idx, b[i].idx);
	}
	printf("%lld\n", ans);

	return 0;
}
