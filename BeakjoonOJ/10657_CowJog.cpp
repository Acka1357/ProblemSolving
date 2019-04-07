#include <stdio.h>

int s[100000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%*d%d", &s[i]);

	int ans = 1, cur = s[N - 1];
	for(int i = N - 2; i >= 0; i--)
		if(s[i] <= cur) cur = s[i], ans++;

	printf("%d\n", ans);
	return 0;
}