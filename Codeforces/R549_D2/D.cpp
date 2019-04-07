#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	ll c;
	while(b){
		c = a; a = b; b = c % b;
	}
	return a;
}

ll N, K, A, B;

int main()
{
	scanf("%lld %lld %lld %lld", &N, &K, &A, &B);
	ll ans_min = N * K, ans_max = 1;
	ll ys[] = {-A + B, -A - B, A + B, A - B};
	for(int i = 0; i <= N; i++){
		for(int j = 0; j < 4; j++){
			ll l = (K * i + ys[j] + K * N) % (K * N);
			ll x = (N * K) / gcd(N * K, l);
			ans_min = min(ans_min, x);
			ans_max = max(ans_max, x);
		}
	}
	printf("%lld %lld\n", ans_min, ans_max);

	return 0;
}
