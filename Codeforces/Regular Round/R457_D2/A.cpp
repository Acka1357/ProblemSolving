#include <stdio.h>

int absx(int x){ return x < 0 ? -x : x; }
int min(int a, int b){ return a < b ? a : b; }

int main()
{
	int x, sh, sm; scanf("%d %d %d", &x, &sh, &sm);
	int want = sh * 60 + sm, ans = 10000000;
	for(int i = 0; i < 24; i++)
		for(int j = 0; j < 60; j++){
			int sum = i * 60 + j;
			if(sum > want) sum -= 60 * 24;
			if(absx(want - sum) % x) continue;
			if(i % 10 == 7 || j % 10 == 7) ans = min(ans, absx(want - sum) / x);
		}
	printf("%d\n", ans);
	return 0;
}