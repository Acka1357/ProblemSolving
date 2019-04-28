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
using namespace std;

int ny[100001], sy[100001], ex[100001], wx[100001];
int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		int P, Q; scanf("%d %d", &P, &Q);
		memset(ny, 0, (Q + 1) * sizeof(ny[0]));
		memset(sy, 0, (Q + 1) * sizeof(sy[0]));
		memset(ex, 0, (Q + 1) * sizeof(ex[0]));
		memset(wx, 0, (Q + 1) * sizeof(wx[0]));
		char d;
		for(int i = 0, x, y; i < P; i++){
			scanf("%d %d %c", &x, &y, &d);
			if(d == 'N') ny[y + 1]++;
			else if(d == 'S') sy[y - 1]++;
			else if(d == 'E') ex[x + 1]++;
			else if(d == 'W') wx[x - 1]++;
			else while(true);
		}

		for(int i = 1; i <= Q; i++){
			ex[i] += ex[i - 1];
			ny[i] += ny[i - 1];
		}
		for(int i = Q - 1; i >= 0; i--){
			wx[i] += wx[i + 1];
			sy[i] += sy[i + 1];
		}
		int xmin = 0, xcnt = wx[0], ymin = 0, ycnt = sy[0];
		for(int i = 1; i <= Q; i++){
			if(xcnt < wx[i] + ex[i]){
				xcnt = wx[i] + ex[i]; xmin = i;
			}
			if(ycnt < ny[i] + sy[i]){
				ycnt = ny[i] + sy[i]; ymin = i;
			}
		}

		printf("Case #%d: %d %d\n", tc, xmin, ymin);
	}
	return 0;
}
