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
using namespace std;

typedef long long ll;

char map[2001][2001], res[2001][2001];
int r1[26], r2[26], c1[26], c2[26];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int R, C; scanf("%d %d", &R, &C);
		for(int i = 0; i < R; i++)
			scanf("%s", map[i]);

		memset(r1, 0x3f, sizeof(r1));
		memset(r2, 0xbf, sizeof(r2));
		memset(c1, 0x3f, sizeof(c1));
		memset(c2, 0xbf, sizeof(c2));

		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(map[i][j] != '.'){
					int alp = map[i][j] - 'a';
					r1[alp] = min(r1[alp], i);
					r2[alp] = max(r2[alp], i);
					c1[alp] = min(c1[alp], j);
					c2[alp] = max(c2[alp], j);
				}

		int ansl = 0;
		for(int i = 0; i < 26; i++)
			if(r2[i] >= 0) ansl = i + 1;
		for(int i = ansl - 1; i >= 0; i--)
			if(r2[i] < 0){
				r1[i] = r1[i + 1];
				r2[i] = r2[i + 1];
				c1[i] = c1[i + 1];
				c2[i] = c2[i + 1];
			}

		bool psb = true;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				res[i][j] = '.';
		// memset(res, '.', sizeof(res));
		for(int i = 0; i < ansl && psb; i++){
			if(r1[i] == r2[i]){
				for(int c = c1[i]; c <= c2[i]; c++)
					res[r1[i]][c] = 'a' + i;
			}
			else if(c1[i] == c2[i]){
				for(int r = r1[i]; r <= r2[i]; r++)
					res[r][c1[i]] = 'a' + i;
			}
			else psb = false;
		}

		for(int i = 0; i < R && psb; i++)
			for(int j = 0; j < C; j++)
				if(map[i][j] != res[i][j]){
					psb = false;
					break;
				}

		if(!psb){
			printf("NO\n");
			continue;
		}

		printf("YES\n");
		printf("%d\n", ansl);
		for(int i = 0; i < ansl; i++)
			printf("%d %d %d %d\n", r1[i] + 1, c1[i] + 1, r2[i] + 1, c2[i] + 1);
	}
	return 0;
}
