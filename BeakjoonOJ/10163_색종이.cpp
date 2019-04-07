#include <stdio.h>

int chk[101][101], ans[101];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, r, c, w, h; i <= N; i++){
		scanf("%d %d %d %d", &r, &c, &w, &h);
		for(int j = 0; j < w; j++)
			for(int k = 0; k < h; k++)
				chk[r + j][c + k] = i;
	}

	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			ans[chk[i][j]]++;

	for(int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}