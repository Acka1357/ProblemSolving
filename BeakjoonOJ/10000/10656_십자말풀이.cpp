#include <stdio.h>

char map[53][54];

int main()
{
	int R, C; scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
		scanf("%s", map[i]);

	int ans = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			if(map[i][j] != '.') continue;
			if((!i || map[i - 1][j] == '#') && (map[i + 1][j] == '.' && map[i + 2][j] == '.')) map[i][j] = '!';
			if((!j || map[i][j - 1] == '#') && (map[i][j + 1] == '.' && map[i][j + 2] == '.')) map[i][j] = '!';
			if(map[i][j] == '!') ans++;
		}

	printf("%d\n", ans);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(map[i][j] == '!') printf("%d %d\n", i + 1, j + 1);

	return 0;
}