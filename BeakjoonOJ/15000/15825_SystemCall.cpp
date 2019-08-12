#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXF = 500000;

int cum[500001];

int main()
{
	ll N, T; scanf("%lld", &N);
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x); 
		cum[x]++;
	}
	scanf("%lld", &T);

	for(int i = 1; i <= MAXF; i++)
		cum[i] += cum[i - 1];

	ll ans = 0x3f3f3f3f3f3f3f3f, size = -1;
	for(int i = 1; i <= MAXF; i++){
		ll sum = (T + i) * cum[i];
		for(int j = i + 1, k = 2; j <= MAXF; j += i, k++)
			sum += (T * k + j + i - 1) * (cum[min(j + i - 1, MAXF)] - cum[j - 1]);
		if(sum < ans) ans = sum, size = i;
	}
	printf("%lld %lld\n", ans, size);

	return 0;
}