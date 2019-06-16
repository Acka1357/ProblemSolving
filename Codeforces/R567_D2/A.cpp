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
	if((A + B) / C == (A / C) + (B / C))
		return !printf("%lld %lld\n", (A + B) / C, 0ll);

	ll ans = min(A, B);
	if(C - (A % C) <= B) ans = min(ans, C - (A % C));
	if(C - (B % C) <= A) ans = min(ans, C - (B % C));
	printf("%lld %lld\n", (A + B) / C, ans);
	return 0;
}
