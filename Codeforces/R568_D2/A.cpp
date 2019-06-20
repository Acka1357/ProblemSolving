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

ll a[3];

int main()
{
	ll D; scanf("%lld %lld %lld %lld", &a[0], &a[1], &a[2], &D);

	sort(a, a + 3);

	printf("%lld\n", (ll)(a[1] < a[0] + D ? D - a[1] + a[0] : 0) +
					 (ll)(a[2] < a[1] + D ? D - a[2] + a[1] : 0));

	return 0;
}
