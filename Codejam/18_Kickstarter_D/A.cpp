#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

#define NINF	-0x3f3f3f3f3f3f3f3f

long long x[500001], s[500001], cum[500001];

int main()
{
   freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstarter_D/A-large.in", "r", stdin);
   freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstarter_D/A-large.out", "w", stdout);

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		long long N, O, D; scanf("%lld %lld %lld", &N, &O, &D);
		long long x1, x2, A, B, C, M, L; 
		scanf("%lld %lld %lld %lld %lld %lld %lld", &x[1], &x[2], &A, &B, &C, &M, &L);

		for(int i = 3; i <= N; i++)
			x[i] = (A * x[i - 1] + B * x[i - 2] + C) % M;		
		for(int i = 1; i <= N; i++){
			s[i] = x[i] + L;
			cum[i] = cum[i - 1] - s[i];
		}

		map<long long, int> cums;
		int odd = 0, nidx = 1;
		long long ans = NINF;
		for(int i = 1; i <= N; i++){
			while(nidx <= N){
				if(odd + (s[nidx] & 1) <= O){
					cums[cum[nidx]]++;
					odd += s[nidx++] & 1;
				}
				else break;
			}
			if(!cums.size()) continue;

			long long target = cum[i - 1] - D;
			auto it = cums.lower_bound(target);
			if(it != cums.end())
				ans = max(ans, -it->first + cum[i - 1]);

			cums[cum[i]]--;
			if(!cums[cum[i]]) cums.erase(cum[i]);
			if(s[i] & 1) odd--;
		}

		if(ans == NINF) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}
