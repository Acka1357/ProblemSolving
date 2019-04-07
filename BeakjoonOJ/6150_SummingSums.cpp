#include <cstdio>

typedef long long ll;

const ll mod = 98765431;

int N, T, a[50001];
ll d = 1, o, pd, po = 1, sum;

int main()
{
	scanf("%d %d", &N, &T);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		sum = (sum + a[i]) % mod;
	}

	if(N == 1) return !printf("0\n");
	if(N == 2) return !printf("%d\n%d\n", T & 1 ? a[1] : a[0], T & 1 ? a[0] : a[1]);

	for(int cp = T; cp; cp >>= 1){
		if(cp & 1){
			ll tmpd = d, tmpo = o, oo = (po * o) % mod;
			d = (pd * tmpd + (N - 1) * oo) % mod;
			o = (pd * tmpo + po * tmpd + (N - 2) * oo) % mod;
		}
		ll tmpd = pd, tmpo = po, oo = (po * po) % mod;
		pd = (tmpd * tmpd + (N - 1) * oo) % mod;
		po = (2 * tmpd * tmpo + (N - 2) * oo) % mod;
	}

	for(int i = 0; i < N; i++)
		printf("%lld\n", (a[i] * d + o * ((sum - a[i] + mod) % mod)) % mod);

	return 0;
}
