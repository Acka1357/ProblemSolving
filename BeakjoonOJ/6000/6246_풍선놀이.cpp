#include <cstdio>

bool chk[10001];

int main()
{
	int N, Q; scanf("%d %d", &N, &Q);
	for(int i = 0, l, t; i < Q; i++){
		scanf("%d %d", &l, &t);
		for(int j = l; j <= N; j += t)
			chk[j] |= true;
	}

	int ans = 0;
	for(int i = 1; i <= N; i++)
		ans += !chk[i];
	printf("%d\n", ans);
	
	return 0;
}