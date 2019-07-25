/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - make white
	Time Complexity: O(N * M)
*/

#include <cstdio>

int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
char map[2000][2001];

int main()
{
	int R, C; scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
		scanf("%s", map[i]);

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			for(int k = 0; k < 4; k++){
				int r = i + dr[k], c = j + dc[k];
				if(r >= 0 && r < R && c >= 0 && c < C)
					map[r][c] = (map[r][c] == 'W' ? 'B' : 'W');
			}

	printf("1\n");
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++)
			printf("%d", map[i][j] == 'W' ? 2 : 3);
		printf("\n");
	}

	return 0;
}