#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

char s[200005];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		ll N, A, B; scanf("%lld %lld %lld", &N, &A, &B);
		scanf("%s", s);

		int len = strlen(s);
		ll ans = 0, r = 0;
		for(int i = 1; i < len; i++){
			if(s[i] == '0') r = i;
			else break;
		}

		if(r == len - 1){
			ll a1 = (N + 1) * B + N * A;
			ll a2 = 2 * (N - 1) * B + 2 * B + (N - 1) * A + 3 * A;
			printf("%lld\n", min(a1, a2));
			continue;
		}

		// ll a1 = 2 * (r + 1) * B + (3 + 2 * r) * A;
		// ll a2 = 2 * (2 * r + 1) * B + (3 + 2 * r) * A;
		// ans += min(a1, a2);
		ans = 2 * (r + 1) * B + (3 + 2 * r) * A;
		ll l = -1;
		for(int i = r + 1; i < len; i++){
			if(s[i] == '0'){
				if(l < 0) l = i;
				continue;
			}
			else if(l >= 0){
				ll cnt = i - l - 1;
				ll a1 = 2 * cnt * B + 2 * (cnt + 2) * A;
				ll a2 = 4 * cnt * B + 2 * cnt * A;
				if(a2 > a1) ans -= (a2 - a1);
				// printf("[%d, %d]: %lld - %lld %lld\n", l, i, cnt, a1, a2);
			}
			l = -1;
		}
		ans += 4 * (l - r) * B + 2 * (l - r) * A;
		ans += 2 * (N - l) * B + (1 + 2 * (N - l)) * A;
		// printf("%d %d %d\n", r + 1, l - r, N - l);
		// printf("%lld %lld %lld = %lld\n", 2 * (r + 1) * B + (3 + 2 * r) * A, 
		// 								  4 * (l - r) * B + 2 * (l - r) * A,
		// 								  2 * (N - l) * B + (1 + 2 * (N - l)) * A,
		// 								  2 * (r + 1) * B + (3 + 2 * r) * A + 
		// 								  4 * (l - r) * B + 2 * (l - r) * A +
		// 								  2 * (N - l) * B + (1 + 2 * (N - l)) * A);
		printf("%lld\n", ans / 2);
	}
	return 0;
}