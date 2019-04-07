#include <stdio.h>

int d[200][200], inf = 987654321;

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &d[i][j]);
			if(!d[i][j]) d[i][j] = inf;
		}

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(d[i][k] + d[i][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];

	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++){
			int cnt = 0;
			for(int k = 0; k < N; k++)
				if(d[i][k] + d[k][j] == d[i][j]) cnt++;
			if(!cnt) printf("%d %d\n", i + 1, j + 1);
		}

	return 0;
}
