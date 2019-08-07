#include <cstdio>

int ans[] = {1, 2, 3, 4, 5, 4, 3, 2};

int main()
{
	int N; scanf("%d", &N);
	printf("%d\n", ans[(N - 1) % 8]);
	return 0;
}