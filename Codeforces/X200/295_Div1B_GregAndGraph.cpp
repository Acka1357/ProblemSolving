#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long ans[502];
int a[502], d[502][502];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			scanf("%lld", &d[i][j]);
	for(int i = N; i > 0; i--)
		scanf("%d", &a[i]);

	for(int k = 1; k <= N; k++){
		int mid = a[k];
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				d[a[i]][a[j]] = min(d[a[i]][a[j]], d[a[i]][mid] + d[mid][a[j]]);

		for(int i = 1; i <= k; i++)
			for(int j = 1; j <= k; j++)
				if(i != j) ans[k] += d[a[i]][a[j]];
	}

	for(int k = N; k > 0; k--)
		printf("%lld%c", ans[k], " \n"[k == 1]);

	return 0;
}