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

ll N, K, S, T;
ll c[200001], f[200001], g[200001], d[200001];

int main()
{
	scanf("%lld %lld %lld %lld\n", &N, &K, &S, &T);
	for(int i = 1; i <= N; i++)
		scanf("%lld %lld", &c[i], &f[i]);
	for(int i = 1; i <= K; i++)
		scanf("%lld", &g[i]);

	sort(g + 1, g + K + 1);
	
	g[++K] = S;
	for(int i = 1; i <= K; i++)
		d[i] = g[i] - g[i - 1];

	ll l = 0, r = 1000000000, m, ans = -1;
	while(l <= r){
		m = (l + r) / 2;

		ll tsum = 0;
		for(int i = 1; i <= K && tsum <= T; i++){
			if(2 * d[i] <= m) tsum += d[i];
			else if(d[i] > m) tsum += T + 1;
			else tsum += m - d[i] + 2 * (2 * d[i] - m);
		}
		if(tsum > T) l = m + 1;
		else ans = m, r = m - 1;
		// printf("%lld: %lld(%lld)\n", m, tsum, ans);
	}

	if(ans < 0) return !printf("-1\n");

	ll ansc = -1;
	for(int i = 1; i <= N; i++)
		if(f[i] >= ans && (ansc < 0 || c[i] < ansc))
			ansc = c[i];
	printf("%lld\n", ansc);

	return 0;
}
