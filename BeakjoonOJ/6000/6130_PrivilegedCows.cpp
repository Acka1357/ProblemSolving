#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, o[1000], a[1000], cnt[4][4], ans, sum;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &o[i]);
		a[i] = o[i];
	}

	sort(a, a + N);
	for(int i = 0; i < N; i++)
		cnt[o[i]][a[i]]++;

	for(int i = 1; i <= 3; i++)
		for(int j = i + 1; j <= 3; j++){
			int tmp = min(cnt[i][j], cnt[j][i]);
			ans += tmp;
			cnt[i][j] -= tmp;
			cnt[j][i] -= tmp;
		}

	for(int i = 1; i <= 3; i++)
		for(int j = i + 1; j <= 3; j++)
			sum += cnt[i][j] + cnt[j][i];
	printf("%d\n", ans + 2 * sum / 3);

	return 0;
}
