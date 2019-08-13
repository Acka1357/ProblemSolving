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
using namespace std;

typedef long long ll;

ll a[300001], d[300001][3];

int main()
{
	ll N, X; scanf("%lld %lld", &N, &X);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	ll ans = 0;
	for(int i = 1; i <= N; i++){
		d[i][0] = max({d[i - 1][0] + a[i], a[i], 0ll});
		d[i][1] = max({d[i - 1][0] + X * a[i], X * a[i], d[i - 1][1] + X * a[i], 0ll});
		d[i][2] = max({d[i - 1][1] + a[i], a[i], d[i - 1][2] + a[i], 0ll});
		ans = max({ans, d[i][0], d[i][1], d[i][2]});
	}
	printf("%lld\n", ans);

	return 0;
}
