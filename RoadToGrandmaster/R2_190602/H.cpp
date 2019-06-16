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

ll N, mult1[] = {1, 2, 1}, mult2[] = {1, 4, 6, 4, 1};

int main()
{
	scanf("%lld", &N);
	ll ans1 = 0, ans2 = 0;
	
	for(int i = 1; i <= min(N, 3ll); i++){
		ll mult = 1;
		for(int j = 1; j <= i; j++) mult *= (N - j + 1);
		for(int j = 1; j <= i; j++) mult /= j;
		ans1 += mult * mult1[i - 1];
	}
	
	for(int i = 1; i <= min(N, 5ll); i++){
		ll mult = 1;
		for(int j = 1; j <= i; j++) mult *= (N - j + 1);
		for(int j = 1; j <= i; j++) mult /= j;
		ans2 += mult * mult2[i - 1];
	}
	printf("%lld\n", ans1 * ans2);

	return 0;
}
