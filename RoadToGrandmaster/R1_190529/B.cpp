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
#include <set>
#include <map>
using namespace std;

typedef long long ll;

struct Sofa{ int l, r, b, t, idx; };

int D, N, M, l[100002], r[100002], b[100002], t[100002];
int cl[100002], cr[100002], cb[100002], ct[100002];
int c1, c2, c3, c4;
Sofa sofa[100001];

int main()
{
	scanf("%d %d %d", &D, &N, &M);
	for(int i = 1, x1, y1, x2, y2; i <= D; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		sofa[i] = {min(x1, x2), max(x1, x2), max(y1, y2), min(y1, y2), i};
		l[sofa[i].l]++; r[sofa[i].r]++; b[sofa[i].b]++; t[sofa[i].t]++;
	}
	scanf("%d %d %d %d", &c1, &c2, &c3, &c4);

	for(int i = 1; i <= N; i++)
		cl[i] = cl[i - 1] + l[i];
	for(int i = N; i > 0; i--)
		cr[i] = cr[i + 1] + r[i];
	for(int i = 1; i <= M; i++)
		ct[i] = ct[i - 1] + t[i];
	for(int i = M; i > 0; i--)
		cb[i] = cb[i + 1] + b[i];

	for(int i = 1; i <= D; i++){
		int cnt1 = cl[sofa[i].r - 1] - (sofa[i].l != sofa[i].r);	// l
		int cnt2 = cr[sofa[i].l + 1] - (sofa[i].l != sofa[i].r);	// r
		int cnt3 = ct[sofa[i].b - 1] - (sofa[i].b != sofa[i].t);	// t
		int cnt4 = cb[sofa[i].t + 1] - (sofa[i].b != sofa[i].t);	// b
		// printf("%d %d %d %d\n", cnt1, cnt2, cnt3, cnt4);
		if(c1 == cnt1 && c2 == cnt2 && c3 == cnt3 && c4 == cnt4)
			return !printf("%d\n", i);
	}

	return !printf("-1\n");
}
