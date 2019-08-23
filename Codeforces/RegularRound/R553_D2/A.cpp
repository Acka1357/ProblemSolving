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

typedef long long ll;

char s[51];

int main()
{
	int N; scanf("%d %s", &N, s);
	int ans = 0x3f3f3f3f;
	int t[4] = {'A' - 'A', 'C' - 'A', 'T' - 'A', 'G' - 'A'};
	for(int r = 3; r < N; r++){
		int sum = 0;
		int a[4] = {s[r - 3] - 'A', s[r - 2] - 'A', s[r - 1] - 'A', s[r] - 'A'};
		for(int i = 0; i < 4; i++)
			sum += min({abs(t[i] - a[i]), 26 + t[i] - a[i], a[i] + 26 - t[i]});
		ans = min(ans, sum);
	}
	printf("%d\n", ans);

	return 0;
}
