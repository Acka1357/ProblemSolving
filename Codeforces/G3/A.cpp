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

int main()
{
	ll A, B, C; scanf("%lld %lld %lld", &A, &B, &C);
	ll ans = 2 * C + 2 * min(A, B);
	ll x = min(A, B);
	A -= x; B -= x;
	printf("%lld\n", ans + (A + B != 0));

	return 0;
}
