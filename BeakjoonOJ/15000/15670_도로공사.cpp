#include <stdio.h>

// 1: up, 0: down
int a[100001], up[100001], down[100001];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++){
		up[i] = up[i - 1] + (i == 1 || a[i - 1] > a[i]);
		down[i] = down[i - 1] + (i == 1 || a[i - 1] < a[i]);
	}

	for(int i = 0, l, r; i < M; i++){
		scanf("%d %d", &l, &r);
		int ans = up[N] - (up[r] - up[l]) + down[r] - down[l];
		if(l > 1){
			if(up[l - 1] != up[l]){
				if(a[l - 1] < a[r]) ans--;
			}
			else if(a[r] < a[l - 1]) ans++;
		}
		if(r < N){
			if(up[r] != up[r + 1]){
				if(a[l] < a[r + 1]) ans--;
			}
			else if(a[l] > a[r + 1]) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}
