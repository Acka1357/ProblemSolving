#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
using namespace std;

typedef long long ll;

int main()
{
	ll N, T; scanf("%lld %lld", &N, &T);
	ll ans = 0, anst = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= N; i++){
		ll S, D; scanf("%lld %lld", &S, &D);
		ll l = 0, r = 100001, m, near = -1;
		while(l <= r){
			m = (l + r) / 2;
			if(S + D * m < T) l = m + 1;
			else r = m - 1, near = S + D * m;
		}
		if(anst > near){
			anst = near;
			ans = i;
		}
	}
	printf("%lld\n", ans);

	return 0;
}