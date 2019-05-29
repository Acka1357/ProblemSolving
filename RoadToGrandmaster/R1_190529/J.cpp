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

int main()
{
	int a1, a2; scanf("%d %d", &a1, &a2);
	int ans = abs(a2 - a1);
	for(a1 = a2; scanf("%d", &a2) == 1; a1 = a2)
		ans = max(ans, abs(a2 - a1));
	printf("%d\n", ans);

	return 0;
}
