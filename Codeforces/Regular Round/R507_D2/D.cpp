#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <chrono>
#include <random>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	long long N, K; scanf("%lld %lld", &N, &K);

	char res[10];
	long long l = 1, r = N, pl, pr, m, cnt = 0, ans;

	while(true){
		assert(++cnt < 4999);
		pl = l, pr = r;

		if(r - l < 73){
			ans = l + (rng() % (r - l + 1));
			printf("%lld %lld\n", ans, ans);
			fflush(stdout);

			scanf("%s", res);
			if(res[0] == 'Y') return 0;
			l = max(1ll, l - K);
			r = min(r + K, N);
			continue;
		}

		m = (l + r) / 2;
		l = max(1ll, l - K);
		r = m;

		printf("%lld %lld\n", l, r);
		fflush(stdout);

		scanf("%s", res);

		if(res[0] == 'Y'){
			if(l == r) return 0;
			continue;
		}

		l = min(N, m + 1);
		r = min(N, pr + K);
	}
	return 0;
}
