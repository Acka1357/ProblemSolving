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

ll d[61];

int main()
{
	ll N; scanf("%lld", &N);

	d[0] = 1;
	for(int i = 2; i <= N; i += 2)
		d[i] = d[i - 2] * 2;

	printf("%lld\n", d[N]);

	return 0;
}
