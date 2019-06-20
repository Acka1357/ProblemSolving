#include <cstdio>

int main()
{
	int N, ans = 0; scanf("%d", &N);
	for(int i = 1; i <= 500; i++)
		for(int j = i; j <= 500; j++)
			if(i * i + N == j * j) ans++;
	printf("%d\n", ans);

	return 0;
}
