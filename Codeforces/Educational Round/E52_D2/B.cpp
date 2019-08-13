#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	long long N, M; scanf("%lld %lld", &N, &M);
	long long ans1 = max(N - M * 2, 0ll);
	long long l = 0, r = N, m, ans2;
	while(l <= r){
		m = (l + r) / 2;
		if((m * (m - 1)) / 2 >= M){
			ans2 = m; r = m - 1;
		}
		else l = m + 1;
	}
	printf("%lld %lld\n", ans1, N - ans2);
	return 0;
}
