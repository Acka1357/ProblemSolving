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
	ll x; scanf("%lld", &x);
	if(x < 0) x = (-x) % 360;
	else x = 360 - x % 360;

	int ansd = 360, ans = -1;
	for(int i = 0; i < 4; i++){
		if(ansd > min(x, 360 - x)) ansd = min(x, 360 - x), ans = i;
		x = (x + 90) % 360;
	}
	printf("%d\n", ans);

	return 0;
}
