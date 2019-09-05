#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		ll N, X; scanf("%lld %lld", &N, &X);
		ll maxd = 0, maxg = -1000000000;
		for(ll i = 0, d, h; i < N; i++){
			scanf("%lld %lld", &d, &h);
			maxd = max(maxd, d);
			maxg = max(maxg, d - h);
		}

		if(X <= maxd) printf("1\n");
		else if(maxg <= 0) printf("-1\n");
		else printf("%lld\n", max(0ll, (X - maxd + maxg - 1) / maxg) + 1);
	}
	return 0;
}