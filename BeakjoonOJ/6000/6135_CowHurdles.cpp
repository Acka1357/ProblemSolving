#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, T, d[301][301];

int main()
{
	memset(d, 0x3f, sizeof(d));
	scanf("%d %d %d", &N, &M, &T);
	for(int i = 0, u, v, h; i < M; i++){
		scanf("%d %d %d", &u, &v, &h);
		d[u][v] = min(d[u][v], h);
	}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
	for(int i = 0, u, v; i < T; i++){
		scanf("%d %d", &u, &v);
		printf("%d\n", d[u][v] == INF ? -1 : d[u][v]);
	}

	return 0;
}