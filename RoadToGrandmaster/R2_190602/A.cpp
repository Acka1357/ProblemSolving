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

const ll mod = 1000000007;

ll a[2002], d[2002][2002];

int main()
{
	ll N, H; scanf("%lld %lld", &N, &H);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	d[0][0] = 1;
	for(int i = 1; i <= N; i++){
		ll cnt = H - a[i];
		if(cnt < 0 || cnt > i) return !printf("0\n");
		d[i][cnt] += d[i - 1][cnt];		// nothing
		if(cnt){
			d[i][cnt] += d[i - 1][cnt - 1];	// open
			d[i][cnt - 1] += cnt * d[i - 1][cnt];	// close
			d[i][cnt - 1] += d[i - 1][cnt - 1]; // self
			if(cnt > 1) d[i][cnt - 1] += (cnt - 1) * d[i - 1][cnt - 1];	// close&open
			d[i][cnt] %= mod; d[i][cnt - 1] %= mod;
		}
	}
	printf("%lld\n", d[N][0]);

	return 0;
}
