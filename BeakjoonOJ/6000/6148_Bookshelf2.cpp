#include <cstdio>

int N, B, a[20], ans;

void dfs(int idx, int sum){
	if(idx == N){
		if(sum >= B && sum - B < ans)
			ans = sum - B;
		return ;
	}
	dfs(idx + 1, sum);
	dfs(idx + 1, sum + a[idx]);
}

int main()
{
	scanf("%d %d", &N, &B);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		ans += a[i];
	}

	dfs(0, 0);
	printf("%d\n", ans);
	
	return 0;
}