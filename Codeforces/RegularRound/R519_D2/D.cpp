#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[100001], s[10][100001], idx[10][100001];

int main()
{
	int N, M; scanf("%d %d", &N, &M); M--;
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &s[i][j]);
			idx[i][s[i][j]] = j;
		}

	int r = 0;
	long long ans = 0;
	for(int i = 0; i < N; i++){
		if(r < i) r = i;
		while(r < N - 1){
			bool psb = true;
			for(int j = 0; j < M; j++){
				// printf("%d: %d->%d: %d %d\n", j,a[r], a[r + 1], idx[j][a[r]], idx[j][a[r + 1]]);
				if(idx[j][a[r]] + 1 != idx[j][a[r + 1]]){
					// printf("!\n");
					psb = false; break;
				}
			}
			if(psb) r++;
			else break;
		}
		// printf("%d %d\n", i, r);
		ans += (r - i + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
