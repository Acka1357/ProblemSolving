#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

struct P{
	int a, b; 
	bool operator <(const P &o)const{
		return a == o.a ? b < o.b : a < o.a;
	}
};

P s[300005];
ll fac[300005], as[300005], bs[300005];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &s[i].a, &s[i].b);
		as[i] = s[i].a; bs[i] = s[i].b;
	}

	fac[1] = 1;
	for(int i = 2; i <= N; i++)
		fac[i] = (fac[i - 1] * i) % mod;

	sort(as + 1, as + N + 1);
	sort(bs + 1, bs + N + 1);
	sort(s + 1, s + N + 1);

	ll ans = fac[N];
	ll l = 1, asort = 1, bsort = 1, csort = 1;
	for(int i = 2; i <= N; i++)
		if(as[i] != as[l]){
			asort = (asort * fac[i - l]) % mod;
			l = i;
		}
	asort = (asort * fac[N - l + 1]) % mod;

	l = 1;
	for(int i = 2; i <= N; i++)
		if(bs[i] != bs[l]){
			bsort = (bsort * fac[i - l]) % mod;
			l = i;
		}
	bsort = (bsort * fac[N - l + 1]) % mod;

	l = 1;
	for(int i = 2; i <= N; i++){
		if(s[i].a < s[i - 1].a || s[i].b < s[i - 1].b){
			csort = 0; break;
		}
		if(s[i].a != s[l].a || s[i].b != s[l].b){
			csort = (csort * fac[i - l]) % mod;
			l = i;
		}
	}
	csort = (csort * fac[N - l + 1]) % mod;

	printf("%lld\n", (ans - asort - bsort + csort + 2 * mod) % mod);

	return 0;
}