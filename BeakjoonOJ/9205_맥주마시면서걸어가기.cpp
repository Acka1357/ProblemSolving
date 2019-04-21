#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Crd{ int x, y; };

bool chk[102];
Crd crd[102];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int N; scanf("%d", &N);
		N += 2;
		for(int i = 0; i < N; i++)
			scanf("%d %d", &crd[i].x, &crd[i].y);

		memset(chk, 0, sizeof(chk));
		queue<int> q;
		q.push(0); chk[0] = true;
		while(!q.empty() && !chk[N - 1]){
			int cur = q.front(); q.pop();
			for(int i = 1; i < N; i++){
				if(chk[i]) continue;
				int d = abs(crd[cur].x - crd[i].x) + abs(crd[cur].y - crd[i].y);
				if(d <= 20 * 50){
					q.push(i);
					chk[i] = true;
				}
			}
		}
		printf("%s\n", chk[N - 1] ? "happy" : "sad");
	}
	return 0;
}