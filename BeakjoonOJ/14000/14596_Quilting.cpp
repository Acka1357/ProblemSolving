#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[102][102], b[102][102], d[102][102];

int main()
{
	int H, W; scanf("%d %d", &H, &W);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%d", &b[i][j]);

	memset(d, 0x3f, sizeof(d));
	memset(d, 0x00, sizeof(d[0]));

	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++){
			d[i][j] = d[i - 1][j];
			if(j > 1) d[i][j] = min(d[i][j], d[i - 1][j - 1]);
			if(j < W) d[i][j] = min(d[i][j], d[i - 1][j + 1]);
			d[i][j] += (a[i][j] - b[i][j]) * (a[i][j] - b[i][j]);
		}

	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= W; i++)
		ans = min(ans, d[H][i]);
	printf("%d\n", ans);

	return 0;
}