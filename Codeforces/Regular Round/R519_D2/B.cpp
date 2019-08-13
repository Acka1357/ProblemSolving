#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

long long N, a[1001], x[1001], ans[1001], ansi;

int main()
{
	scanf("%lld", &N);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	x[0] = a[1];
	for(int i = 1; i <= N; i++){
		bool psb = true;
		for(int j = 1; j < i; j++)
			x[j] = a[j + 1] - a[j];
		// for(int j = 0; j < i; j++)
		// 	printf("%lld ", x[j]);
		// printf("\n");
		for(int j = 1; j <= N; j++)
			if(a[j] != x[(j - 1) % i] + a[j - 1]){
				psb = false;
				break;
			}
		if(psb) ans[ansi++] = i;
	}
	
	printf("%lld\n", ansi);
	for(int i = 0; i < ansi; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}