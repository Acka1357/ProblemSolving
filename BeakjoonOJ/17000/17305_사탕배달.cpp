/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - satang
	Time Complexity: O(NlogN)
*/

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;

int s3[250001], s5[250001], cnt3, cnt5;
ll cum3[250001], cum5[250001];

int main()
{
	ll N, W; scanf("%lld %lld", &N, &W);
	for(int i = 0, t, s; i < N; i++){
		scanf("%d %d", &t, &s);
		if(t == 3) s3[++cnt3] = s;
		else s5[++cnt5] = s;
	}

	sort(s3 + 1, s3 + cnt3 + 1, greater<int>());
	sort(s5 + 1, s5 + cnt5 + 1, greater<int>());

	for(int i = 1; i <= N; i++){
		cum3[i] = cum3[i - 1] + s3[i];
		cum5[i] = cum5[i - 1] + s5[i];
	}

	ll ans = 0;
	for(int i = 0; i <= cnt3 && 3 * i <= W; i++)
		ans = max(ans, cum3[i] + cum5[(W - 3 * i) / 5]);
	printf("%lld\n", ans);

	return 0;
}