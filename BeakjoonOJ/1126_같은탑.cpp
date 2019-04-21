// solution:
// d[i][j]: i번째 블럭까지 사용해서 두 탑의 높이 차가 j일때 낮은 탑의 최대 높이
// 각 블럭은 사용하지 않거나, 높은 탑에 보태거나, 낮은 탑에 보태는 경우가 있다.

// 시간복잡도: O(N * sum(H))
// 분류: DP
// 난이도: 1500

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h[51], d[51][500001], sum;

int main()
{
	memset(d, 0xff, sizeof(d));

	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &h[i]);

	d[0][0] = 0;
	for(int i = 0; i < N; i++){
		sum += h[i];
		for(int j = 0; j <= sum; j++){
			if(d[i][j] < 0) continue;
			d[i + 1][j] = max(d[i + 1][j], d[i][j]);
			d[i + 1][j + h[i + 1]] = max(d[i + 1][j + h[i + 1]], d[i][j]);
			if(j >= h[i + 1]) d[i + 1][j - h[i + 1]] = max(d[i + 1][j - h[i + 1]], d[i][j] + h[i + 1]);
			else d[i + 1][h[i + 1] - j] = max(d[i + 1][h[i + 1] - j], d[i][j] + j);
		}
	}
	printf("%d\n", d[N][0] ? d[N][0] : -1);

	return 0;
}