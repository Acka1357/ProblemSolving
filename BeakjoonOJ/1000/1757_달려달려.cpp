// 분류: DP
// 난이도: 1250

#include <cstdio>
#include <algorithm>
using namespace std;

int v[10002], d[10002][501];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		scanf("%d", &v[i]);

	d[0][0] = 0;
	for(int i = 0; i < N; i++){
		d[i + 1][0] = max(d[i + 1][0], d[i][0]);
		for(int j = 0; j <= M; j++){
			if(j != M)
				d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + v[i + 1]);
			if(i + j <= N)
				d[i + j][0] = max(d[i + j][0], d[i][j]);
		}
	}
	printf("%d\n", d[N][0]);

	return 0;
}