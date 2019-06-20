#include <stdio.h>

int ans[101], o[101], oi[101];

int main()
{
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	for(int i = 1; i <= M; i++){
		scanf("%d", &o[i]);
		oi[o[i]] = i;
	}
	for(int i = 0, n, idx; i < K; i++){
		scanf("%d %d", &n, &idx);
		ans[idx] = n;
		if(n == 1) return !printf("%d\n", idx);
	}

	int cnt = 0, po = 0, poi = 0;
	for(int i = 1; i <= N; i++)
		if(ans[i]){
			if(oi[ans[i]]){
				if(oi[ans[i]] >= oi[1] && cnt + oi[ans[i]] + !oi[1] <= i) break;
				po = i; poi = oi[ans[i]];
				cnt = i - oi[ans[i]];
			}
			else cnt++;
		}

	for(int i = po + 1; i <= N; i++)
		if(!ans[i]){
			if(poi + 1 < oi[1]) ans[i] = o[++poi];
			else{
				printf("%d\n", i);
				break;
			}
		}

	return 0;
}
