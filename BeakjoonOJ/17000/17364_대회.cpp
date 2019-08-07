#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct Seg{
	int l, r;
	bool operator <(const Seg &o)const{
		return r == o.r ? l > o.l : r < o.r;
	}
};

Seg seg[100001];

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &seg[i].l, &seg[i].r);

	sort(seg, seg + N);

	int ans = 0, nr = 0;
	multiset<int> out;
	for(int i = 1; i < K; i++) out.insert(0);

	for(int i = 0; i < N; i++){
		if(seg[i].l <= nr) continue;
		auto it = out.lower_bound(seg[i].l);
		if(out.size() && it != out.begin()){
			out.erase(--it);
			out.insert(seg[i].r);
		}
		else ans++, nr = seg[i].r;
	}
	printf("%d\n", ans);

	return 0;
}