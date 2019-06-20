#include <cstdio>
#include <algorithm>
using namespace std;

int D, N, M, x[50000];

bool psb(int d){
	int cur = 0, cnt = 0;
	for(int i = 0; i < N && cnt <= M; i++){
		if(x[i] - cur < d) cnt++;
		else cur = x[i];
	}
	return cnt + (D - cur < d) <= M;
}

int main()
{
	scanf("%d %d %d", &D, &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	sort(x, x + N);

	int l = 0, r = D, m, ans = 0;
	while(l <= r){
		m = (l + r) / 2;
		if(psb(m)) l = m + 1, ans = m;
		else r = m - 1;
	}
	printf("%d\n", ans);

	return 0;
}
