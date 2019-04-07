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

int l;
char s[65001];

int main()
{
	scanf("%d %s", &l, s);

	ll ans = 0;
	for(int i = 0; s[i]; i++)
		if((s[i] - '0') % 2 == 0)
			ans += i + 1;
	printf("%lld\n", ans);

	return 0;
}
