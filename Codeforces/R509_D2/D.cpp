#include <stdio.h>
#include <algorithm>
using namespace std;

int l[200001], r[200001], cum[200001];

int main()
{
	int N, H; scanf("%d %d", &N, &H);
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &l[i], &r[i]);

	for(int i = 1; i <= N; i++)
		cum[i] = cum[i - 1] + r[i] - l[i];

	int idx = 1, ans = 0;
	for(int i = 1; i <= N; i++){
		while(l[i] - l[idx] - (cum[i - 1] - cum[idx - 1]) >= H){
			ans = max(cum[i - 1] - cum[idx - 1] + H, ans);
			idx++;
		}
	}
	while(idx <= N){
		ans = max(cum[N] - cum[idx - 1] + H, ans);
		idx++;
	}

	printf("%d\n", ans);
	return 0;
}