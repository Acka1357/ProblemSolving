#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		ll st, it, ex; scanf("%lld %lld %lld", &st, &it, &ex);

		ll vmin = -1, vmax = -1;
		ll l = 0, r = ex, m;
		while(l <= r){
			m = (l + r) / 2;
			if(st + ex - m > it + m){
				vmin = m;
				r = m - 1;
			}
			else l = m + 1;
		}

		l = 0, r = ex;
		while(l <= r){
			m = (l + r) / 2;
			if(st + ex - m > it + m){
				vmax = m;
				l = m + 1;
			}
			else r = m - 1;
		}

		if(vmin < 0 && vmax < 0) printf("0\n");
		else if(vmin < 0 || vmax < 0) printf("%lld\n", vmax + 1);
		else printf("%lld\n", vmax - vmin + 1);
	}
	return 0;
}