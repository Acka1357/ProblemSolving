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

ll N, M, K, a[200001];

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N);

	ll cnt = M / (K + 1);
	printf("%lld\n", a[N - 1] * (M - cnt) + a[N - 2] * cnt);

	return 0;
}
