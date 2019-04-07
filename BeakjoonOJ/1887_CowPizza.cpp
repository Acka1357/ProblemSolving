#include <cstdio>

int bit[20], mask[52];

int main()
{	
	for(int i = 0; i < 20; i++)
		bit[i] = (1 << i);

	int T, N, Z; scanf("%d %d", &T, &N);
	for(int i = 0, x; i < N; i++){
		scanf("%d", &Z);
		while(Z--){
			scanf("%d", &x);
			mask[i] |= bit[x - 1];
		}
	}

	int ans = (1 << T);
	for(int st = ans - 1; st >= 0; st--){
		bool chk = false;
		for(int i = 0; i < N; i++)
			if((st & mask[i]) == mask[i]){
				chk = true; break;
			}
		if(chk) ans--;
	}
	printf("%d\n", ans);

	return 0;
}
