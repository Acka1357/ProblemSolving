#include <cstdio>
#include <cstring>

int N, dr[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
char map[7][7];

void set_dol(int r, int c, char me, char en){
	for(int d = 0; d < 8; d++){
		int nr = r, nc = c;
		while(true){
			nr += dr[d]; nc += dc[d];
			if(nr < 0 || nc < 0 || nr >= 6 || nc >= 6) break;
			if(map[nr][nc] != en) break;
		}
		if(nr < 0 || nc < 0 || nr >= 6 || nc >= 6) continue;
		if(map[nr][nc] != me) continue;
		while(true){
			map[nr][nc] = me;
			if(nr == r && nc == c) break;
			nr -= dr[d]; nc -= dc[d];
		}
	}
}

int main()
{
	memset(map, '.', sizeof(map));
	map[2][2] = map[3][3] = 'W';
	map[2][3] = map[3][2] = 'B';

	scanf("%d", &N);
	for(int i = 0, r, c; i < N; i++){
		scanf("%d %d", &r, &c);
		set_dol(r - 1, c - 1, (i & 1) ? 'W' : 'B', (i & 1) ? 'B' : 'W');
	}

	int bwin = 0;
	for(int i = 0; i < 6; i++){
		map[i][6] = 0; printf("%s\n", map[i]);
		for(int j = 0; j < 6; j++)
			bwin += (map[i][j] == 'W' ? -1 : (map[i][j] == 'B' ? 1 : 0));
	}
	printf("%s\n", bwin > 0 ? "Black" : "White");

	return 0;
}
