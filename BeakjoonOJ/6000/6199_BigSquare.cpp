#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, ans, sq[10001], l1[7954], l2[7954], r[10000], c[10000], pcnt, ccnt;
char map[100][101];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", map[i]);
		for(int j = 0; j < N; j++)
			if(map[i][j] == 'J'){
				r[ccnt] = i; c[ccnt++] = j;
			}
	}

	memset(sq, 0xff, sizeof(sq));
	for(int i = 0; i <= N; i++)
		sq[i * i] = i;

	int ans = 0;
	for(int sum = N * N; sum > 0; sum--){
		for(int l = 0; l * l <= sum; l++)
			if(sq[sum - l * l] >= 0){
				l1[pcnt] = l; l2[pcnt++] = sq[sum - l * l];
			}
	}

	int r1, r2, r3, c1, c2, c3;
	for(int pi = 0; !ans && pi < pcnt; pi++){
		int dr = l1[pi], dc = l2[pi];
		for(int ci = 0; ci < ccnt; ci++){
			r1 = r[ci] - dr, c1 = c[ci] - dc;
			if(r1 < 0 || c1 < 0) continue;
			if(c[ci] + dr < N && r[ci] >= dr + dc){
				r2 = r1 - dc, c2 = c1 + dr;
				r3 = r2 + dr, c3 = c2 + dc;
				if(map[r1][c1] != 'B' && map[r2][c2] != 'B' && map[r3][c3] != 'B')
					if((map[r1][c1] != 'J') + (map[r2][c2] != 'J') + (map[r3][c3] != 'J') <= 1){
						ans = dr * dr + dc * dc;
						break;
					}
			}
			if(c[ci] >= dr + dc && r[ci] + dc < N){
				r2 = r1 + dc, c2 = c1 - dr;
				r3 = r2 + dr, c3 = c2 + dc;
				if(map[r1][c1] != 'B' && map[r2][c2] != 'B' && map[r3][c3] != 'B')
					if((map[r1][c1] != 'J') + (map[r2][c2] != 'J') + (map[r3][c3] != 'J') <= 1){
						ans = dr * dr + dc * dc;
						break;
					}
			}

		}
	}

	printf("%d\n", ans);

	return 0;
}
