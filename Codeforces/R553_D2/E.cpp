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

ll v[100001], cum[100001];

int main()
{
	ll N, ans = 0; scanf("%lld", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &v[i]);

	for(int i = 0; i < N; i++)
		ans += v[i] * (N - v[i] + 1);
	for(int i = 1; i < N; i++)
		ans -= min(v[i - 1], v[i]) * (N - max(v[i - 1], v[i]) + 1);
	printf("%lld\n", ans);

	return 0;
}
