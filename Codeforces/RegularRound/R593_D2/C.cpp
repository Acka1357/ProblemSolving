#include <cstdio>

int ans[303][303];

int main()
{
	int N, cur = 1; scanf("%d", &N);
	for(int c = 0; c < N; c++){
		if(c & 1){
			for(int r = 0; r < N; r++)
				ans[r][c] = cur++;
		}
		else{
			for(int r = N - 1; r >= 0; r--)
				ans[r][c] = cur++;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			printf("%d%c", ans[i][j], " \n"[j == N - 1]);
		
	return 0;
}