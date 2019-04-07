#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, a[10000], b[10000];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(int j = 0; j < M; j++)
		scanf("%d", &b[j]);

	sort(a, a + N);
	sort(b, b + M);

	int ans = N;
	for(int i = M - 1, ni = N - 1; i >= 0; i--)
		if(a[ni] > b[i]) ans++, ni--;
	printf("%d\n", ans);

	return 0;
}
