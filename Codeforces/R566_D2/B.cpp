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
#include <map>
using namespace std;

typedef long long ll;

int R, C, sum, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
char mp[500][501];

int main()
{
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
		scanf("%s", mp[i]);

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			sum += (mp[i][j] == '*');

	for(int i = 1; i < R - 1; i++)
		for(int j = 1; j < C - 1; j++){
			if(mp[i][j] != '*') continue;
			int cnt = 1;

			for(int d = 0; d < 4; d++){
				int r = i + dr[d], c = j + dc[d], len = 0;
				while(r >= 0 && r < R && c >= 0 && c < C && mp[r][c] == '*'){
					len++; r += dr[d]; c += dc[d];
				}
				if(len == 0){
					cnt = -1; break;
				}
				else cnt += len;
			}

			if(cnt == sum) return !printf("YES\n");
		}

	return !printf("NO\n");
}
