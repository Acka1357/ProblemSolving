#include <cstdio>
#include <algorithm>
using namespace std;

char map[301][101][102];
int cum[101][102];

int main()
{
	int R, C, T, K, A, B; 
	scanf("%d %d %d %d %d %d", &R, &C, &T, &K, &A, &B);
	for(int i = 1; i <= R; i++)
		scanf("%s", map[0][i] + 1);

	for(int t = 0; t < T; t++){
		for(int r = 1; r <= R; r++)
			for(int c = 1; c <= C; c++)
				cum[r][c] = cum[r - 1][c] + cum[r][c - 1] - cum[r - 1][c - 1] + (map[t][r][c] == '*');

		for(int r = 1; r <= R; r++)
			for(int c = 1; c <= C; c++){
				int cnt = cum[min(r + K, R)][min(c + K, C)] - cum[max(r - K - 1, 0)][min(c + K, C)] - cum[min(r + K, R)][max(c - K - 1, 0)] + cum[max(r - K - 1, 0)][max(c - K - 1, 0)] - (map[t][r][c] == '*');
				if(map[t][r][c] == '*' && A <= cnt && cnt <= B) map[t + 1][r][c] = '*';
				else if(map[t][r][c] != '*' && A < cnt && cnt <= B) map[t + 1][r][c] = '*';
			}
	}

	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++)
			printf("%c", map[T][i][j] == '*' ? '*' : '.');
		printf("\n");
	}

	return 0;
}