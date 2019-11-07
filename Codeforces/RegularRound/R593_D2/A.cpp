#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		int ans = 0;
		for(int i = 0; i <= B; i++){
			int tb1 = min(i, C / 2);
			int tb2 = min((B - tb1) / 2, A);
			ans = max(ans, tb1 * 3 + tb2 * 3);
		}
		printf("%d\n", ans);
	}
	return 0;
}