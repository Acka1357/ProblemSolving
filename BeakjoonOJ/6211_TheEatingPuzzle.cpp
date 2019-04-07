#include <cstdio>

int S, N, ans, w[21];

void pick(int idx, int sum){
	if(idx == N){
		if(sum > ans) ans = sum;
		return ;
	}
	pick(idx + 1, sum);
	if(sum + w[idx] <= S)
		pick(idx + 1, sum + w[idx]);
}

int main()
{
	scanf("%d %d", &S, &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &w[i]);

	pick(0, 0);
	printf("%d\n", ans);

	return 0;
}
