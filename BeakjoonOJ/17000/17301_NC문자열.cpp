/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - NC string
	Time Complexity: O(N)
*/

#include <cstdio>
#include <cstring>

typedef long long ll;

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

ll fac[100002];

ll nPr(int n, int r){
	return (fac[n] * mod_inv(fac[n - r], mod)) % mod;
}

int main()
{
	int N; scanf("%d", &N);

	char s[11];
	int n = 0, c = 0, nc = 0, cn = 0;
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		bool has_n = false, has_c = false, has_nc = false, has_cn = false;
		for(int j = 0; s[j]; j++){
			if(s[j] == 'N'){
				has_n = true;
				if(has_c) has_cn = true;
			}
			else if(s[j] == 'C'){
				has_c = true;
				if(has_n) has_nc = true;
			}
		}

		if(has_nc) nc++;
		else if(has_cn) cn++;
		else if(has_n) n++;
		else if(has_c) c++;
		else return -1;
	}

	for(int i = fac[0] = 1; i <= N; i++)
		fac[i] = (fac[i - 1] * i) % mod;

	ll all = 0, sumn = 0, sumc = 0;
	for(int i = 0; i <= N; i++)
		all = (all + nPr(N, i)) % mod;
	for(int i = 0; i <= c; i++)
		sumc = (sumc + nPr(c, i)) % mod;
	for(int i = 0; i <= n; i++)
		sumn = (sumn + nPr(n, i)) % mod;

	printf("%lld\n", (all - (((cn + 1) * ((sumn * sumc) % mod)) % mod) + mod) % mod);

	return 0;
}