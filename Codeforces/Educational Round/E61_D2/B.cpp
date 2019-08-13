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

ll cum[300001], a[300001], q[300001];

int main()
{
	int N, M; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	scanf("%d", &M);
	for(int i = 1; i <= M; i++)
		scanf("%lld", &q[i]);
	
	sort(a + 1, a + N + 1);

	for(int i = 1; i <= N; i++)
		cum[i] = cum[i - 1] + a[i];

	for(int i = 1; i <= M; i++)
		printf("%lld\n", cum[N] - a[N - q[i] + 1]);

	return 0;
}
