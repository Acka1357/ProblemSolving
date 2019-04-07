#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

struct Seg{
	int l, r;
	bool operator <(const Seg &o)const{
		return r == o.r ? l < o.l : r < o.r;
	}
}

int N, Q, t, d[5001][3][5001];
Seg seg[5001];

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= Q; i++)
		scanf("%d %d", &seg[i].l, &seg[i].r);

	memset(d, 0xff, sizeof(d));
	sort(seg + 1, seg + N + 1);

	d[0][0][0] = 0;
	for(int i = 1; i <= Q; i++){
		for(int j = 0; j < 3; j++)
			for(int cur = 0; cur <= seg[i].r; cur++){
				if(cur < seg[i].l){
					d[i][j][cur] = d[i - 1][j][cur];
					continue;
				}
				if(d[i - 1][j][cur - 1] >= 0)
					d[i][j][cur] = max(d[i][j][cur], d[i - 1][j][cur - 1] + 1);
				if(d[i][j][cur - 1] >= 0)
					d[i][j][cur] = max(d[i][j][cur], d[i][j][cur - 1] + 1);
			}
		for(int j = 1; j < 3; j++)
			for(int cur = 0; cur <= seg[i].r; cur++){
				if(cur < seg[i].l){
					continue;
				}
			}
	}

	printf("%d\n", d[Q][2][N]);

	return 0;
}
