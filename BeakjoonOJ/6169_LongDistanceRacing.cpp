#include <cstdio>

int main()
{
	int M, T, U, F, D; scanf("%d %d %d %d %d", &M, &T, &U, &F, &D);
	
	char x;
	int sum = 0, ans = 0;
	while(ans < T){
		scanf(" %c", &x);
		if(x == 'f') sum += 2 * F;
		else sum += U + D;
		if(sum > M) break;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}