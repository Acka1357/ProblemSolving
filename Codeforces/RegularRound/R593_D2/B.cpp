#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll modpow(ll x, ll p){
	if(p == 1) return x;
	if(p == 0) return 1ll;
	ll sq = modpow(x, p / 2);
	ll ret = (sq * sq) % mod;
	if(p & 1) ret = (ret * x) % mod;
	return ret;
}

int main()
{
	ll N, M; scanf("%lld %lld", &N, &M);
	printf("%lld\n", modpow((modpow(2ll, M) - 1 + mod) % mod, N));
	return 0;
}