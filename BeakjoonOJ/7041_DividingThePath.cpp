#include <cstdio>
#include <algorithm>
using namespace std;

struct Seg{
	int l, r;
	bool operator <(const Seg &o)const{
		return l == o.l ? r > o.r : l < o.l;
	}
};

Seg seg[1000];

int main()
{
	int N, L, A, B; scanf("%d %d %d %d", &N, &L, &A, &B);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &seg[i].l, &seg[i].r);
		seg[i].l -= seg[i].l & 1; seg[i].r += seg[i].r & 1;
	}

	sort(seg, seg + N);
	int last = 0;
	for(int i = 0; i < N; i++){
		if(seg[i].l < last) return !printf("-1\n");
		if(seg[i])
	}
	int ans = 0, last = 0, rem = 0;
	for(int i = 0; i < N; i++){
		if(seg[i].l < last) return !printf("-1\n");
		if(!rem) last = min(last + rem + ((last + rem) & 1), seg[i].l - (seg[i].l & 1));
		int len = seg[i].l - (seg[i].l & 1) - last;
		int q = len / (2 * B), r = len % (2 * B);
		ans += len / (2 * B);
		rem = seg[i].r 
	}
	printf("%d\n", ans);

	return 0;
}
