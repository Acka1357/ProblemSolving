#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int M, P, d[602][301], a[301], b[301], ca[301], cb[301];

int main()
{
	scanf("%d %d", &M, &P);
	for(int i = 1; i <= P; i++)
		scanf("%d %d", &a[i], &b[i]);

	for(int i = 1; i <= P; i++){
		ca[i] = ca[i - 1] + a[i];
		cb[i] = cb[i - 1] + b[i];
	}

	memset(d, 0xff, sizeof(d));
	d[0][0] = 0; d[1][0] = M;

	int ans = 2 * P;
	for(int i = 2; i <= ans; i++)
		for(int j = i / 2; j <= P; j++){
			for(int k = (i - 1) / 2; k <= j; k++){
				if(d[i - 1][k] < ca[j] - ca[k]) continue;
				if(cb[j] - cb[k] > M) continue;
				d[i][j] = max(d[i][j], M - (cb[j] - cb[k]));
			}
			if(d[i][P] >= 0) ans = i;
		}

	printf("%d\n", ans + 1);

	return 0;
}
