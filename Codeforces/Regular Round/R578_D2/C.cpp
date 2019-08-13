#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	ll c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}
int main()
{
	ll N, M, Q; scanf("%lld %lld %lld", &N, &M, &Q);
	ll G = gcd(N, M);
	while(Q--){
		ll s1, s2, e1, e2; scanf("%lld %lld %lld %lld", &s1, &s2, &e1, &e2);
		ll sn = (s2 - 1) / ((s1 == 1 ? N : M) / G);
		ll en = (e2 - 1) / ((e1 == 1 ? N : M) / G);
		printf("%s\n", sn == en ? "YES" : "NO");
	}
	return 0;
}
