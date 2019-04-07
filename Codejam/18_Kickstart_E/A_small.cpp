#include <stdio.h>
#include <algorithm>
using namespace std;

int a[5000];

int main()
{
   freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstart_E/A-small-attempt0.in", "r", stdin);
   freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstart_E/A-small-attempt0.out", "w", stdout);

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, K; scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);

		sort(a, a + N);

		int ans = 0, cnt = 0, day = 1;
		for(int i = 0; i < N; i++)
			if(a[i] >= day){
				ans++;
				cnt++;
				if(cnt == K) cnt = 0, day++;
			}

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
