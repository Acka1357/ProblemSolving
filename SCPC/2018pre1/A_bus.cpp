#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200000], t[200000];

int main()
{
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, K; scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);

		sort(a, a + N);

		int l = 1, r = N, m, ans = 1, idx;
		while(l <= r){
			m = (l + r) / 2;

			bool psb = true;
			for(int i = idx = 0; i < m; i++)
				t[i] = a[i];
			for(int i = m; i < N && psb; i++){
				if(idx == m) idx = 0;
				if(a[i] - t[idx] <= K) psb = false;
				else t[idx++] = a[i];
			}
			if(psb) r = m - 1, ans = m;
			else l = m + 1;
		}

		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}