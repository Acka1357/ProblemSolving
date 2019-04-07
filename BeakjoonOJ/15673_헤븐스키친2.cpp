#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, a[100002], dl[2][100002], dr[2][100002], cl[2][100002], cr[2][100002];

int main()
{
	scanf("%lld", &N);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	memset(dl[0], 0x3f, sizeof(dl[0]));
	memset(dl[1], 0xbf, sizeof(dl[1]));
	memset(dr[0], 0x3f, sizeof(dr[0]));
	memset(dr[1], 0xbf, sizeof(dr[1]));

	for(int i = 1; i <= N; i++){
		dl[0][i] = min(dl[0][i - 1] + a[i], a[i]);
		dl[1][i] = max(dl[1][i - 1] + a[i], a[i]);
	}
	for(int i = N; i > 0; i--){
		dr[0][i] = min(dr[0][i + 1] + a[i], a[i]);
		dr[1][i] = max(dr[1][i + 1] + a[i], a[i]);
	}

	cl[0][0] = cl[0][N + 1] = cr[0][0] = cr[0][N + 1] = 0x3f3f3f3f3f3f3f3f;
	cl[1][0] = cl[1][N + 1] = cr[1][0] = cr[1][N + 1] = 0xbfbfbfbfbfbfbfbf;
	for(int i = 1; i <= N; i++){
		cl[0][i] = min(cl[0][i - 1], dl[0][i]);
		cl[1][i] = max(cl[1][i - 1], dl[1][i]);
	}
	for(int i = N; i > 0; i--){
		cr[0][i] = min(cr[0][i + 1], dr[0][i]);
		cr[1][i] = max(cr[1][i + 1], dr[1][i]);
	}

	ll ans = 0xbfbfbfbfbfbfbfbf;
	for(int i = 1; i < N; i++)
		ans = max({ans, cl[0][i] * cr[0][i + 1], cl[1][i] * cr[1][i + 1], cl[0][i] * cr[1][i + 1], cl[1][i] * cr[0][i + 1]});
	printf("%lld\n", ans);

	return 0;
}
