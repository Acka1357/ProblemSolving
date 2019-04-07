#include <stdio.h>

int max(int a, int b){return a > b ? a : b; }

int t1[101], t2[101], s1[101], s2[101];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &t1[i], &s1[i]);
	for(int i = 0; i < M; i++)
		scanf("%d %d", &t2[i], &s2[i]);

	int ans = 0, i1 = 0, i2 = 0;
	while(i1 < N && i2 < M){
		ans = max(ans, s2[i2] - s1[i1]);
		if(t1[i1] > t2[i2]) t1[i1] -= t2[i2++];
		else if(t1[i1] < t2[i2]) t2[i2] -= t1[i1++];
		else i1++, i2++;
	}
	while(i1 < N) ans = max(ans, s2[M - 1] - s1[i1++]);
	while(i2 < M) ans = max(ans, s2[i2++] - s1[N - 1]);

	printf("%d\n", ans);
	return 0;
}