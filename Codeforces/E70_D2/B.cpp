#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct Point{ ll x, y;
	bool operator <(const Point &o) const{ return x == o.x ? y < o.y : x < o.x; }
};
struct Crd{ int r, c; };
struct Edge{ int to, cost; };
struct Node{ int cur; ll cost;
	bool operator <(const Node &o)const{ return cost > o.cost; }
};

char s[2000001];
ll d[10][10][10][10], ans[10][10];

void floyd(ll dist[][10]){
	for(int k = 0; k < 10; k++)
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
	memset(d, 0x3f, sizeof(d));
	memset(ans, 0x3f, sizeof(ans));

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++){
			for(int p = 0; p < 10; p++){
				d[i][j][p][(p + i) % 10] = min(d[i][j][p][(p + i) % 10], 1ll);
				d[i][j][p][(p + j) % 10] = min(d[i][j][p][(p + j) % 10], 1ll);
			}
			floyd(d[i][j]);
		}


	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++)
		s[i] -= '0';

	for(int i = 0; i < 10; i++)
		for(int j = i; j < 10; j++){
			ll sum = (s[0] == 0) ? 0 : (d[i][j][0][s[0]] - 1);
			if(sum >= inf) continue;
			for(int si = 1; si < l; si++){
				if(d[i][j][s[si - 1]][s[si]] >= inf){
					sum = inf; break;
				}
				sum += d[i][j][s[si - 1]][s[si]] - 1;
			}
			ans[i][j] = ans[j][i] = sum;
		}

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			printf("%lld%c", ans[i][j] < inf ? ans[i][j] : -1, " \n"[j == 9]);

	return 0;
}
