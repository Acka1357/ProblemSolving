#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

ll a[100005];
int t, ts[100005], idx[100005], V, e[200][200], d[200][200];
vector<int> has[100];

int main()
{
	memset(d, 0x3f, sizeof(d));

	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &a[i]);
		for(ll x = a[i], j = 0, b = 1; x; j++, b <<= 1)
			if(x & b) has[j].push_back(i), x ^= b;
	}

	for(int i = 0; i < 64; i++)
		if(has[i].size() >= 3) return !printf("3\n");

	for(int i = 0; i < 64; i++)
		if(has[i].size() == 2){
			int u = has[i][0], v = has[i][1];
			if(!idx[u]) idx[u] = ++V;
			if(!idx[v]) idx[v] = ++V;
			u = idx[u], v = idx[v];
			d[u][v] = d[v][u] = e[u][v] = e[v][u] = 1;
		}

	int ans = inf;
	for(int k = 1; k <= V; k++){
		for(int i = 1; i < k; i++)
			for(int j = i + 1; j < k; j++)
				if(e[j][k] && e[k][i]) ans = min(ans, d[i][j] + 2);

		for(int i = 1; i <= V; i++)
			for(int j = 1; j <= V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	printf("%d\n", ans >= inf ? -1 : ans);

	return 0;
}