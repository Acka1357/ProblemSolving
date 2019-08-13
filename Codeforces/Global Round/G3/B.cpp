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

ll N, M, A, B, K, a[200001], b[200001];

int main()
{
	scanf("%lld %lld %lld %lld %lld", &N, &M, &A, &B, &K);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= M; i++)
		scanf("%lld", &b[i]);

	if(N <= K || M <= K) return !printf("-1\n");
	
	ll ans = -1, bi = 1;
	for(int i = 1; i <= min(K, N); i++){
		a[i] += A;
		while(bi <= M && b[bi] <= a[i]) bi++;
		if(bi > M || bi + K - i + 1 > M) return !printf("-1\n");
		ans = max(ans, b[bi + K - i + 1] + B);
	}
	printf("%lld\n", ans);

	return 0;
}
