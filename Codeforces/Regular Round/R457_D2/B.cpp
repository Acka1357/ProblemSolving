#include <stdio.h>

int cnt[100061];

void add(int idx, int val){ cnt[100000 + idx] += val; }
int get_cnt(int idx){ return cnt[100000 + idx]; }

int main()
{
	long long N, K; scanf("%lld %lld", &N, &K);

	int kcnt = 0;
	for(long long i = 60, p = (1ll << 60); i >= 0 && N; i--, p >>= 1)
		if(N >= p) add(i, 1), N -= p, kcnt++;

	if(kcnt > K) return 0 & printf("NO\n");

	bool chk = true;
	int last = 60;
	for(int i = 60; i >= -100000; i--){
		int icnt = get_cnt(i);
		if(!icnt) continue;
		last = i;
		if(chk && icnt <= K - kcnt){
			kcnt += icnt;
			add(i, -icnt);
			add(i - 1, 2 * icnt);
		}
		else chk = false;
	}

	while(kcnt < K){
		add(last, -1);
		add(--last, 2);
		kcnt++;
	}

	printf("YES\n");
	for(int i = 60; i >= -100000; i--)
		while(cnt[100000 + i]--) printf("%d ", i);
	printf("\n");

	return 0;
}