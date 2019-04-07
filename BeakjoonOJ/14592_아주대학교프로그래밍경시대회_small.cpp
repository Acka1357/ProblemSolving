#include <cstdio>
#include <algorithm>
using namespace std;

int N, ws = -1, wc, wl, ans;

int main()
{
	scanf("%d", &N);
	for(int i = 1, s, c, l; i <= N; i++){
		scanf("%d %d %d", &s, &c, &l);
		if(ws > s) continue;
		else if(ws < s) ans = i;
		else if(wc < c) continue;
		else if(wc > c) ans = i;
		else if(wl < l) continue;
		else if(wl > l) ans = i;
		else while(true);
		ws = s, wc = c, wl = l;
	}
	printf("%d\n", ans);

	return 0;
}
