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

int main()
{
	ll N, ans = 0; scanf("%lld", &N);
	for(int i = 2; i < N; i++)
		ans += (N - i + 2) * (N - i + 1);
	printf("%lld\n", ans);

	return 0;
}
