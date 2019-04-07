#include <stdio.h>
#include <algorithm>
using namespace std;

int N, even[50001], odd[50001];

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", i & 1 ? &odd[i / 2] : &even[i / 2]);

		sort(even, even + N / 2 + 1);
		sort(odd, odd + N / 2);

		int ans = -1;
		bool psb = true;
		for(int i = 0; i < N - 1 && psb; i++){
			if(i & 1){
				if(odd[i / 2] > even[(i + 1) / 2]){
					ans = i; psb = false;
				}
			}
			else{
				if(even[i / 2] > odd[i / 2]){
					ans = i; psb = false;
				}
			}
		}

		if(psb) printf("Case #%d: OK\n", tc);
		else printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}