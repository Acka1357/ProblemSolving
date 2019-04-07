#include <cstdio>

typedef long long ll;

char s[51];
ll N, r = 31, mod = 1234567891, ans = 0;

int main()
{
	scanf("%lld %s", &N, s);
	for(int i = N - 1; i >= 0; i--){
		ans *= r;
		ans += (s[i] - 'a' + 1);
		ans %= mod;
	}
	printf("%lld\n", ans);

	return 0;
}