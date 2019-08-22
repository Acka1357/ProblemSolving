#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int B, P, F, H, C; scanf("%d %d %d %d %d", &B, &P, &F, &H, &C);

		int ans = 0;
		for(int i = 0; i <= P; i++){
			int pcnt = min(B / 2, i);
			int s1 = pcnt * H;
			int s2 = min((B - pcnt * 2) / 2, F) * C;
			ans = max(ans, s1 + s2);
		}
		printf("%d\n", ans);
	}
	return 0;
}