#include <cstdio>
#include <algorithm>
using namespace std;

int a[20000];

int main()
{
	int N, B; scanf("%d %d", &N, &B);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N);

	int ans = 0, sum = 0;
	for(int i = N - 1; i >= 0; i--)
		if((sum += a[i]) >= B)
			return !printf("%d\n", N - i);
	printf("-1\n");

	return 0;
}