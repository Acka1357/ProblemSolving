/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - unify color
	Time Complexity: O(N)
*/

#include <cstdio>

typedef long long ll;

ll N, C, a[250001], ld[250001], rd[250001];

int main()
{
	scanf("%lld %lld", &N, &C);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	for(int i = 2; i <= N; i++)
		ld[i] = ld[i - 1] + (a[i] > a[i - 1] ? C - a[i] + a[i - 1] : a[i - 1] - a[i]);
	for(int i = N - 1; i > 0; i--)
		rd[i] = rd[i + 1] + (a[i] > a[i + 1] ? C - a[i] + a[i + 1] : a[i + 1] - a[i]);

	ll ans = N * C, ansi = -1;
	for(int i = 1; i <= N; i++){
		ll cnt = (ld[i] > rd[i] ? ld[i] : rd[i]);
		if(cnt < ans) ans = cnt, ansi = i;
	}
	printf("%lld\n%lld\n", ansi, ans);

	return 0;
}