#include <cstdio>

int main()
{
	int N, ans = 0; scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		if(!(N % i)) ans += i;
	printf("%d\n", ans);

	return 0;
}
