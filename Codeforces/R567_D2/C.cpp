#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int len[1002][1002], cum[1002][1002][26];
char map[1002][1002];

int rec(int r1, int r2, int c1, int c2, int x){
	return cum[r2][c2][x] - cum[r1 - 1][c2][x] - cum[r2][c1 - 1][x] + cum[r1 - 1][c1 - 1][x];
}

int main()
{
	int R, C; scanf("%d %d", &R, &C);
	for(int i = 1; i <= R; i++)
		scanf("%s", map[i] + 1);

	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			for(int k = 0; k < 26; k++){
				cum[i][j][k] = cum[i - 1][j][k] + cum[i][j - 1][k] - cum[i - 1][j - 1][k] + (('a' + k) == map[i][j]);
				// printf("cum[%d][%d][%d]: %d\n", i, j, k, cum[i][j][k]);
			}

	for(int i = R; i > 0; i--)
		for(int j = 1; j <= C; j++){
			if(map[i + 1][j] == map[i][j]) len[i][j] = len[i + 1][j] + 1;
			else len[i][j] = 1;
			// printf("(%d,%d): %d\n", i, j, len[i][j]);
		}

	ll ans = 0;
	for(int i = 1; i <= R; i++){
		for(int l = 1, r = 1; r <= C; r++){
			if(len[i][r] != len[i][l]) l = r;
			int h = len[i][r];
			if(i + 3 * h - 1 > R) continue;
			// printf("row:%d l:%d r:%d h:%d\n", i, l, r, h);
			// printf("%d %d %d\n", map[i + h][l] != map[i + 2 * h][l], 
			// 	rec(i + h, i + 2 * h - 1, l, r, map[i + h][l] - 'a') != (r - l + 1) * h, 
			// 	rec(i + 2 * h, i + 3 * h - 1, l, r, map[i + 2 * h][l] - 'a') != (r - l + 1) * h);
			if(map[i + h][l] != map[i + 2 * h][l] &&
				rec(i, i + h - 1, l, r, map[i][l] - 'a') == (r - l + 1) * h &&
				rec(i + h, i + 2 * h - 1, l, r, map[i + h][l] - 'a') == (r - l + 1) * h &&
				rec(i + 2 * h, i + 3 * h - 1, l, r, map[i + 2 * h][l] - 'a') == (r - l + 1) * h){
					ans += r - l + 1;
			}
			else{
				l = r;
				if(map[i + h][l] != map[i + 2 * h][l] &&
					rec(i, i + h - 1, l, r, map[i][l] - 'a') == (r - l + 1) * h &&
					rec(i + h, i + 2 * h - 1, l, r, map[i + h][l] - 'a') == (r - l + 1) * h &&
					rec(i + 2 * h, i + 3 * h - 1, l, r, map[i + 2 * h][l] - 'a') == (r - l + 1) * h)
						ans += r - l + 1;
				else l = r + 1;
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}
