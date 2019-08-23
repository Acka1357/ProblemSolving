#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

char s[200004];
// -x x -y y
int minlx[200004], maxlx[200004], minly[200004], maxly[200004];
int minrx[200004], maxrx[200004], minry[200004], maxry[200004]; 
int curx[200004], cury[200004], dx[256], dy[256];
int dx4[4] = {0, 1, 0, -1}, dy4[4] = {1, 0, -1, 0};

int main()
{
	dy['D'] = dy['A'] = dx['W'] = dx['S'] = 0;
	dy['S'] = dx['A'] = -1;
	dy['W'] = dx['D'] = 1;

	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%s", s + 1);
		int L = strlen(s + 1);
		memset(minlx, 0, (L + 3) * sizeof(minlx[0]));
		memset(maxlx, 0, (L + 3) * sizeof(minlx[0]));
		memset(minly, 0, (L + 3) * sizeof(minlx[0]));
		memset(maxly, 0, (L + 3) * sizeof(minlx[0]));
		memset(minrx, 0, (L + 3) * sizeof(minlx[0]));
		memset(maxrx, 0, (L + 3) * sizeof(minlx[0]));
		memset(minry, 0, (L + 3) * sizeof(minlx[0]));
		memset(maxry, 0, (L + 3) * sizeof(minlx[0]));
		memset(curx, 0, (L + 3) * sizeof(minlx[0]));
		memset(cury, 0, (L + 3) * sizeof(minlx[0]));

		int x = 0, y = 0;
		for(int i = 1; i <= L; i++){
			x += dx[s[i]]; y += dy[s[i]];
			curx[i] = x; cury[i] = y;
			minlx[i] = min(minlx[i - 1], x);
			maxlx[i] = max(maxlx[i - 1], x);
			minly[i] = min(minly[i - 1], y);
			maxly[i] = max(maxly[i - 1], y);
		}

		for(int i = L; i > 0; i--){
			int nx = min(L + 1, ((i / 450) + 1) * 450);
			x = y = 0;
			for(int j = i; j < nx; j++){
				x += dx[s[j]]; y += dy[s[j]];
				minrx[i] = min(minrx[i], x);
				maxrx[i] = max(maxrx[i], x);
				minry[i] = min(minry[i], y);
				maxry[i] = max(maxry[i], y);	
			}
			minrx[i] = min(minrx[i], x + minrx[nx]);
			maxrx[i] = max(maxrx[i], x + maxrx[nx]);
			minry[i] = min(minry[i], y + minry[nx]);
			maxry[i] = max(maxry[i], y + maxry[nx]);
		}

		// for(int i = 1; i <= L; i++)
		// 	printf("%d: %d %d %d %d\n", i, minlx[i], maxlx[i], minly[i], maxly[i]);
		// for(int i = 1; i <= L; i++)
		// 	printf("%d: %d %d %d %d\n", i, minrx[i], maxrx[i], minry[i], maxry[i]);
		// 	printf("---\n");

		ll ans = (maxlx[L] - minlx[L] + 1ll) * (maxly[L] - minly[L] + 1ll);
		for(int i = 0; i <= L; i++){
			ll xmin = minlx[i], xmax = maxlx[i];
			ll ymin = minly[i], ymax = maxly[i];
			ll x = curx[i], y = cury[i];
			for(int d = 0; d < 4; d++){
				ll nx = x + dx4[d], ny = y + dy4[d];
				ll nxmin = min(xmin, nx + minrx[i + 1]);
				ll nxmax = max(xmax, nx + maxrx[i + 1]);
				ll nymin = min(ymin, ny + minry[i + 1]);
				ll nymax = max(ymax, ny + maxry[i + 1]);
				// printf("%d: %d - %lld %lld %lld %lld\n", i, d, nxmin, nxmax, nymin, nymax);
				ans = min(ans, (nxmax - nxmin + 1ll) * (nymax - nymin + 1ll));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
