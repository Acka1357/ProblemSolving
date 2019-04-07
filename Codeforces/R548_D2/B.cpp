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

ll N, a[200001];

int main()
{
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &a[i]);

	ll ans = 0, last = 1000000001;
	for(int i = N - 1; i >= 0; i--){
		last = min(max(0ll, last - 1), a[i]);
		ans += last;
	}
	printf("%lld\n", ans);

	return 0;
}
