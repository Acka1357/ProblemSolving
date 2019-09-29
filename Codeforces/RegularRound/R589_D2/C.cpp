#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

vector<int> ps;
bool notP[100005];

ll modpow(ll x, ll p){
	if(p == 0) return 1;
	if(p == 1) return x;
	ll ret = modpow(x, p / 2);
	ret = (ret * ret) % mod;
	if(p & 1) ret = (ret * x) % mod;
	return ret;
}

int main()
{
	ll X, N; scanf("%lld %lld", &X, &N);
	for(ll i = 2; i * i <= X; i++){
		if(notP[i]) continue;
		if(!(X % i)){
			ps.push_back(i);
			while(!(X % i)) X /= i;
		}
		for(ll j = i * i; j * j <= X; j += i)
			notP[j] = true;
	}

	if(X > 1) ps.push_back(X);

	ll ans = 1;
	for(ll p : ps){
		ll cnt = 0;
		for(ll NN = N; NN >= p; NN /= p)
			cnt += NN / p;
		ans = (ans * modpow(p, cnt)) % mod;
	}
	printf("%lld\n", ans);

	return 0;
}