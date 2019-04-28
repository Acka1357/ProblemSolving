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

int a[100], b[100];

int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		int N, K; scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < N; i++)
			scanf("%d", &b[i]);

		int ans = 0;
		for(int i = 0; i < N; i++){
			int amax = a[i], bmax = b[i];
			for(int j = i; j < N; j++){
				amax = max(amax, a[j]);
				bmax = max(bmax, b[j]);
				if(max(amax, bmax) - min(amax, bmax) <= K)
					ans++;
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
