#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int CAN_D = 1000000;

bool chk[10000];
int H, N, x[10000], y[10000], d[10000];

int dist(int u, int v){
	return (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]);
}

int main()
{
	scanf("%d %d", &H, &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &y[i]);

	memset(d, 0x3f, sizeof(d));
	for(int i = 0; i < N; i++)
		if(y[i] <= 1000) d[i] = 1;

	for(int st = 0; st < N; st++){
		int x = -1, xd = INF;
		for(int i = 0; i < N; i++)
			if(!chk[i] && xd >= d[i]){
				x = i; xd = d[i];
			}
		if(x < 0) break;
		chk[x] = true;
		for(int to = 0; to < N; to++)
			if(dist(x, to) <= CAN_D) d[to] = min(d[to], d[x] + 1);
	}

	int ans = N;
	for(int i = 0; i < N; i++)
		if(y[i] >= H - 1000) ans = min(ans, d[i]);
	printf("%d\n", ans);

	return 0;
}