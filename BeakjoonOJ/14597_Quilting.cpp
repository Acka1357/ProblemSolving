#include <stdio.h>
#include <algorithm>

int d[101][101];
char a[101][101], b[101][101];

int main()
{
	int H, W; scanf("%d %d", &H, &W);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%u", &a[i][j]);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%u", &b[i][j]);

	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			d[i][j] = std::min({d[i - 1][j], d[i - 1][j - 1], d[i - 1][j + 1]}) + (a[i][j] - b[i][j]) * (a[i][j] - b[i][j]);

	int ans = d[H][1];
	for(int i = 0; i < )
	return 0;
}