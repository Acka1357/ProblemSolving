#include <stdio.h>
#include <algorithm>
using namespace std;

int n[200000], nmax[200000], nmin[200000];

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N; scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &n[i]);

		nmax[0] = n[0];
		nmin[N - 1] = n[N - 1];

		for(int i = 1; i < N; i++){
			nmax[i] = max(nmax[i - 1], n[i]);
			nmin[N - i - 1] = min(nmin[N - i], n[N - i - 1]);
		}

		int ans = 0;
		for(int i = 0; i < N; i++)
			if(nmax[i] <= n[i] && n[i] <= nmin[i])
				ans++;

		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}