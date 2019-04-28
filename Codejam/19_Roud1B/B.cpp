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

typedef long long ull;

ull p(int p){ return (ull)1 << p; }

ull calc(ull org, int div_p, bool modchk = false){
	if(modchk && ((org % p(div_p + 7)) % p(div_p))) return 101;
	return (org % p(div_p + 7)) >> div_p;
}

int main()
{
	int T, W; for(scanf("%d %d", &T, &W); T--;){
		ull w128, w40;
		printf("128\n"); fflush(stdout);
		scanf("%llu", &w128);
		printf("40\n"); fflush(stdout);
		scanf("%llu", &w40);

		ull x[7];
		for(x[6] = 0; x[6] <= 100; x[6]++){
			if(w128 < x[6] * p(21)) while(true);
			ull tmp = w128 - x[6] * p(21);
			x[3] = calc(tmp, 42);
			x[4] = calc(tmp, 32);
			x[5] = calc(tmp, 25, true);

			if(w40 < p(13) * x[3] + p(10) * x[4] + p(8) * x[5] + p(6) * x[6]) continue;
			tmp = w40 - p(13) * x[3] - p(10) * x[4] - p(8) * x[5] - p(6) * x[6];
			x[1] = calc(tmp, 40);
			x[2] = calc(tmp, 20, true);
			while(x[3] != calc(tmp, 13));

			bool psb = true;
			for(int i = 1; i <= 5; i++)
				if(x[i] > 100) psb = false;
			if(!psb) continue;

			ull sum128 = p(42) * x[3] + p(32) * x[4] + p(25) * x[5] + p(21) * x[6];
			ull sum40 = p(40) * x[1] + p(20) * x[2] + p(13) * x[3] + p(10) * x[4] + p(8) * x[5] + p(6) * x[6];
			if(sum128 == w128 && sum40 == w40) break;
			if(x[6] == 100) while(true);
		}
		printf("%llu %llu %llu %llu %llu %llu\n", x[1], x[2], x[3], x[4], x[5], x[6]);
		fflush(stdout);
		int res; scanf("%d", &res);
		if(res < 0) break;
	}
	return 0;
}
