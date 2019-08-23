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

ll a[300002], gap[300002];

int main()
{
	ll N, K; scanf("%lld %lld", &N, &K);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i < N; i++)
		gap[i] = a[i + 1] - a[i];

	sort(gap + 1, gap + N);

	ll ans = 0;
	for(int i = 1; i <= N - K; i++)
		ans += gap[i];
	printf("%lld\n", ans);

	return 0;
}
