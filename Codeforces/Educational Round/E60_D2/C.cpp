#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll absx(ll x){
	return x < 0 ? -x : x;
}

ll x1, y1, x2, y2, N, dx, dy;
char s[100001];
ll dsx[256], dsy[256], cumx[100002], cumy[100002];

int main()
{
	scanf("%lld %lld %lld %lld %lld %s", &x1, &y1, &x2, &y2, &N, s);
	dx = x2 - x1, dy = y2 - y1;
	dsx['R'] = dsy['U'] = 1;
	dsx['L'] = dsy['D'] = -1;

	for(int i = 1; i <= N; i++){
		cumx[i] = cumx[i - 1] + dsx[s[i - 1]];
		cumy[i] = cumy[i - 1] + dsy[s[i - 1]];
	}

	ll ans = INF, ax = cumx[N], ay = cumy[N];
	for(int i = 0; i <= N; i++){
		ll l = 0, r = 1000000000000ll, m;
		while(l <= r){
			m = (l + r) / 2;
			ll sumx = ax * m + cumx[i], sumy = ay * m + cumy[i];
			if(absx(dx - sumx) + absx(dy - sumy) <= m * N + i){
				ans = min(ans, m * N + i);
				r = m - 1;
			}
			else l = m + 1;
		} 
	}
	printf("%lld\n", ans == INF ? -1 : ans);

	return 0;
}
