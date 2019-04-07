#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Crd{
	int r, c;
	bool operator <(const Crd &o)const{
		return c < o.c;
	}
};

Crd crd[1000];
bool ex[2][1000];
int rc[1000], d[1000][1001][4];

int main()
{
	int N, K, B; scanf("%d %d %d", &N, &K, &B);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &crd[i].r, &crd[i].c);

	sort(crd, crd + N);

	int M = 0; rc[M++] = crd[0].c; ex[crd[0].r - 1][M - 1] = true;
	for(int i = 1; i < N; i++){
		if(rc[M - 1] != crd[i].c) rc[M++] = crd[i].c;
		ex[crd[i].r - 1][M - 1] = true;
	}

	memset(d, 0x3f, sizeof(d));
	d[0][1][0] = d[0][2][3] = 2;
	if(!ex[1][0]) d[0][1][1] = 1;
	if(!ex[0][0]) d[0][1][2] = 1;

	for(int i = 1; i < M; i++){
		int len = rc[i] - rc[i - 1];
		for(int j = min(K, 2 * i); j > 0; j--){
			d[i][j][0] = min({d[i-1][j-1][0], d[i-1][j-1][1], d[i-1][j-1][2], d[i-1][j-1][3]}) + 2;
			d[i][j][0] = min(d[i][j][0], d[i-1][j][0] + 2 * len);
			if(j > 1) d[i][j][3] = min({d[i-1][j-2][0], d[i-1][j-2][1], d[i-1][j-2][2], d[i-1][j-2][3]}) + 2;
			d[i][j][3] = min(d[i][j][3], d[i-1][j][3] + 2 * len);
			d[i][j][3] = min(d[i][j][3], min({d[i-1][j-1][1], d[i-1][j-1][2], d[i-1][j-1][3]}) + len + 1);
			if(!ex[1][i]){	// only top
				d[i][j][1] = min({d[i-1][j-1][0], d[i-1][j-1][1], d[i-1][j-1][2], d[i-1][j-1][3]}) + 1;
				d[i][j][1] = min(d[i][j][1], min(d[i-1][j][1], d[i-1][j][3]) + len);
			}
			else if(!ex[0][i]){		// only bottom
				d[i][j][2] = min({d[i-1][j-1][0], d[i-1][j-1][1], d[i-1][j-1][2], d[i-1][j-1][3]}) + 1;
				d[i][j][2] = min(d[i][j][2], min(d[i-1][j][2], d[i-1][j][3]) + len);
			}
		}
	}

	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= K; i++)
		for(int j = 0; j < 4; j++)
			ans = min(ans, d[M - 1][i][j]);
	printf("%d\n", ans);

	return 0;
}
