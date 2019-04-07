#include <cstdio>

int S, E, cnt[10];

int main()
{
	scanf("%d %d", &S, &E);
	for(int i = S; i <= E; i++){
		for(int n = i; n; n /= 10)
			cnt[n % 10]++;
	}
	for(int i = 0; i < 10; i++)
		printf("%d%c", cnt[i], " \n"[i == 9]);

	return 0;
}
