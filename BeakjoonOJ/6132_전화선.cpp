// solution:
// d[i][j]: i번 건물을 높이 h로 했을때 i번째 건물까지의 최소 비용
// d[i][j] <- d[i - 1][k] + |h[i] - k| + (h[i] - j)^2 (j >= h[i])
// 그냥하면 O(N * H^2)으로 시간초과의 위험이 있지만
// d[i - 1] 상태의 100부터의 감소치와 1부터의 증가치 최솟값을 O(H)로 미리 계산해두면
// 각 d[i]의 갱신은 절댓값을 신경쓰지 않고 비교 연산만으로 갱신이 가능하다.

// 시간복잡도: O(NH)
// 분류: DP
// 난이도: 1500 ~ 1750

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h[100001], d[100001][101], hh[101], lh[101];

int main()
{
	int N, C; scanf("%d %d", &N, &C);
	for(int i = 1; i <= N; i++)
		scanf("%d", &h[i]);

	memset(d, 0x3f, sizeof(d));
	memset(d, 0x00, sizeof(d[0]));
	for(int i = 1; i <= N; i++){
		hh[100] = d[i - 1][100];
		for(int j = 99; j > 0; j--)
			hh[j] = min(hh[j + 1] + C, d[i - 1][j]);
		lh[1] = d[i - 1][1];
		for(int j = 2; j <= 100; j++)
			lh[j] = min(lh[j - 1] + C, d[i - 1][j]);
		for(int j = h[i]; j <= 100; j++)
			d[i][j] = min(hh[j], lh[j]) + (j - h[i]) * (j - h[i]);
	}

	int ans = 0x3f3f3f3f;
	for(int i = h[N]; i <= 100; i++)
		ans = min(ans, d[N][i]);
	printf("%d\n", ans);

	return 0;
}
