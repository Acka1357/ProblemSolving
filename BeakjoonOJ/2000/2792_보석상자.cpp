// 분류: Binary Search

#include <cstdio>

int N, M, a[300000];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &a[i]);

	int l = 1, r = 1000000000, m, ans = 0;
	while(l <= r){
		m = (l + r) / 2;
		int cnt = 0;
		for(int i = 0; i < M; i++){
			cnt += (a[i] + m - 1) / m;
			if(cnt > N) break;
		}
		if(cnt > N) l = m + 1;
		else r = m - 1, ans = m;
	}
	printf("%d\n", ans );

	return 0;
}