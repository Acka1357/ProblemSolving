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

ll a[300001], vmin[300001];

int main()
{
	ll N, M, K; scanf("%lld %lld %lld", &N, &M, &K);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	memset(vmin, 0x3f, sizeof(vmin));

	ll ans = 0, cum = 0;
	for(int i = 1; i <= N; i++){
		vmin[i % M] = min(vmin[i % M] + K, cum + K);
		for(int j = 0; j < M; j++)
			ans = max(ans, cum + a[i] - vmin[j]);
		ans = max(ans, a[i] - K);
		cum += a[i];
	}
	printf("%lld\n", ans);

	return 0;
}
