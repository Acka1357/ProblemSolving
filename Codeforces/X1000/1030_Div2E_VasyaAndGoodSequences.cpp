#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int cnt[300005], cum[300005], even[300005], odd[300005];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		ll x; scanf("%lld", &x);
		cnt[i] = __builtin_popcountll(x);
		cum[i] = cum[i - 1] + cnt[i];
		if(cum[i] & 1) odd[i]++;
		else even[i]++;
		odd[i] += odd[i - 1];
		even[i] += even[i - 1];
	}

	ll ans = 0;
	int cur = 0;
	for(int i = 1; i <= N - 59; i++){
		if(cur & 1) ans += odd[N] - odd[i + 59];
		else ans += even[N] - even[i + 59];
		cur += cnt[i];
	}

	for(int i = 1; i <= N; i++){
		int cmax = 0, sum = 0;
		for(int j = 1; j <= 60; j++){
			if(i + j - 1 > N) break;
			cmax = max(cmax, cnt[i + j - 1]);
			sum += cnt[i + j - 1];
			if(!(sum & 1) && sum >= cmax * 2) ans++; 
		}
	}
	printf("%lld\n", ans);

	return 0;
}