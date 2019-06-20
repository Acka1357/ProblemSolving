#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAXV	10000

int N, K, d[10001][51], ncnt[10001][51], gcnt[10001], tc;
bool ex[10001][51];

int main()
{
	int T = 2;
	while(T--){
		scanf("%d", &N);
	// while(scanf("%d", &N) == 1){
		K = 0;
		memset(d, 0, sizeof(d));
		memset(ncnt, 0, sizeof(ncnt));
		memset(gcnt, 0, sizeof(gcnt));
		memset(ex, 0, sizeof(ex));

		for(int i = 1, h; i <= N; i++){
			scanf("%d", &h); K += h;
			for(int j = 0, x; j < h; j++){
				scanf("%d", &x);
				ncnt[x][i]++;
				if(!ex[x][i]){
					gcnt[x]++; ex[x][i] = true;
				}
			}
		}

		ex[0][0] = true;
		for(int i = 1; i <= MAXV; i++){
			if(!gcnt[i]){
				for(int j = 0; j <= N; j++){
					d[i][j] = d[i - 1][j];
					ex[i][j] = ex[i - 1][j];
				}
				continue;
			}
			for(int j = 1; j <= N; j++){
				if(!ex[i][j]) continue;
				for(int k = 0; k <= N; k++){
					if(!ex[i - 1][k]) continue;
					if(j == k) d[i][j] = max(d[i][j], d[i - 1][k] + (gcnt[i] == 1));
					else d[i][j] = max(d[i][j], d[i - 1][k] + ex[i][k]);
				}
			}
		}

		int ans = d[MAXV][1];
		for(int i = 2; i <= N; i++)
			ans = max(ans, d[MAXV][i]);

		ans = 2 * K - N - 1 - 2 * ans;
		for(int i = 1; i <= MAXV; i++)
			for(int j = 1; j <= N; j++)
				if(ncnt[i][j]) ans -= 2 * (ncnt[i][j] - 1);
				
		printf("Case %d: %d\n", ++tc, ans);
	}
	return 0;
}
