#include <cstdio>

int main()
{
	int N, ans = 0; scanf("%d", &N);
	while(true){
		if(ans * (ans + 1) == N - 1)
			break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
