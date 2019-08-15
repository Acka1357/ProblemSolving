#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[1000006], d[1000006][3][3];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	M += 2;
	int ans = 0;
	for(int i = 1; i <= M; i++)
		for(int a = 0; a < 3; a++)
			for(int b = 0; b < 3; b++){
				int used = a + b, lm = min({2, cnt[i] - used, cnt[i + 1] - b, cnt[i + 2]});
				for(int make = 0; make <= lm; make++){
					d[i][b][make] = max(d[i][b][make], d[i - 1][a][b] + make + (cnt[i] - used - make) / 3);
					ans = max(ans, d[i][b][make]);
				}
			}
	printf("%d\n", ans);

	return 0;
}