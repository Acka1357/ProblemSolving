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
	int T; for(scanf("%d", &T); T--;){
		ll N, X; scanf("%lld %lld", &N, &X);
		if(N == 1 && X == 1) printf("1\n");
		else printf("%lld\n", 2 * X);
	}
	return 0;
}
