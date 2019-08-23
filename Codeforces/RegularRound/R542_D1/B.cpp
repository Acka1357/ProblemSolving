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
typedef unsigned long long ull;

const ll NINF = -2000000000;

ll N, a[2000], K;

ll find_wa(){
	ll res = 0, cur = 0, k = -1;
	for(int i = 0; i < N; i++){
		cur += a[i];
		if(cur < 0) cur = 0, k = i;
		res = max(res, (i - k) * cur);
	}
	return res;
}

ll find_ac(){
	ll res = NINF;
	for(int l = 0; l < N; l++){
		ll sum = 0;
		for(int r = l; r < N; r++)
			res = max(res, (r - l + 1) * (sum += a[r]));
	}
	return res;
}

bool set_a(int m, int r, ll s1){
	for(int i = 0; i < m; i++)
		a[i] = -1;
	a[m] = m - s1;

	ll sum = K + s1 * (r + 1);
	if(sum % (m + 1)) return false;
	ll s2 = sum / (m + 1);
	ll a1 = s2 / (r - m);
	for(int i = m + 1; i < r; i++)
		a[i] = a1;
	a[r] = s2 - a1 * (r - m - 1);
	return true;
}

ll absx(ll a){
	return a < 0 ? -a : a;
}

int main()
{
	scanf("%lld", &K);
	if(K <= 1000000)
		return printf("%d\n%lld\n", 1, -K) & 0;

	N = 2000;
	int len = 2000;
	for(ll s1 = 2; ; s1++){
		for(ll m = 2; m < s1; m++){
			if((K + len * s1) % (m + 1)) continue;
			if(set_a(m, len - 1, s1)){
				if(absx(find_wa() - find_ac()) == K){
					printf("%lld\n", N);
					for(int i = 0; i < len; i++)
						printf("%lld%c", a[i], " \n"[i == len - 1]);
					return 0;
				}
			}
		}
	}

	printf("-1\n");
	return 0;
}
