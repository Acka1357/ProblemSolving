#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 1000000007;

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = ext_gcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else x = 1, y = 0;
	return d;
}

ll mod_inv(ll a, ll m){
	ll x, y;
	ext_gcd(a, m, x, y);
	return (m + x % m) % m; 
}

vector<int> adj[100005];
int clr[100005];

pll dfs(int cur, int par){
	vector<pll> ch;
	ll mult = 1;
	for(int nxt : adj[cur]){
		if(nxt == par) continue;
		pll ret = dfs(nxt, cur);
		mult = ((ret.first + ret.second) * mult) % mod;
		ch.push_back(ret);
	}

	if(clr[cur] == 1)
		return {0ll, mult};

	ll d1 = mult, d2 = 0;
	for(pll &ret : ch){
		ll tmp = (mult * mod_inv(ret.first + ret.second, mod)) % mod;
		d2 += tmp * ret.second;
		d2 %= mod;
	}

	return {d1, d2};
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, x; i < N; i++){
		scanf("%d", &x);
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i = 0; i < N; i++)
		scanf("%d", &clr[i]);

	printf("%lld\n", dfs(0, 0).second);

	return 0;
}