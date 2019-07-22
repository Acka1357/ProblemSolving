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

int a[100001];

int main()
{
	int T; for(scanf("%d", &T); T--;){
		int N; scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		sort(a, a + N);

		int ans = 0;
		for(int i = N - 2; i >= 0; i--){
			ans = max(ans, min(a[i] - 1, i));
		}
		printf("%d\n", ans);
	}
	return 0;
}
