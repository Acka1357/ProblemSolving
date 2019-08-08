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
	int tc; for(scanf("%d", &tc); tc--;){
		ll N; scanf("%lld", &N);
		ll b = sqrt(N);
		ll a = max(2.0, sqrt(b));

		while((a * (a - 1) * (b + 1)) / 2 <= N) b++;
		ll r = N - (a * (a - 1) * b) / 2;

		printf("133");
		for(int i = 0; i < r; i++) printf("7");
		for(int i = 2; i < a; i++) printf("3");
		for(int i = 0; i < b; i++) printf("7");
		printf("\n");
		// printf("%lld\n", 1 + r + a + b);
	}
	return 0;
}
