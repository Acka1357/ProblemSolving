#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000];

int main()
{
	int N, A, B; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	scanf("%d %d", &A, &B);

	long long ans = 0;
	for(int i = 0; i < N; i++){
		a[i] -= min(a[i], A);
		ans += (a[i] + B - 1) / B + 1;
	}
	printf("%lld\n", ans);

	return 0;
}