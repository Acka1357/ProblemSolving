#include <stdio.h>

int map[100][100];

int main()
{
	for(int T = 10; T--;){
		int tc; scanf("%d", &tc);

		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				scanf("%d", &map[i][j]);

		int r = 99, c = 0;
		for(int i = 0; i < 100; i++)
			if(map[r][i] == 2) c = i;

		while(r){
			if(c && map[r][c - 1] == 1){
				while(c && map[r][c - 1] == 1) c--;
			}
			else{
				while(c < 99 && map[r][c + 1] == 1) c++;
			}
			r--;
		}

		printf("#%d %d\n", tc, c);
	}
	return 0;
}
