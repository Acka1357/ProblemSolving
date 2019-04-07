#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int T, N, pcnt, ncnt, p[50000], n[50000], cur, sum, ans;

int main()
{
	scanf("%d %d", &T, &N);
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		if(x > 0) p[pcnt++] = x;
		else n[ncnt++] = x;
	}

	sort(p, p + pcnt); 
	sort(n, n + ncnt, greater<int>());
	
	for(int pi = 0, ni = 0; pi + ni < N && sum <= T; ans++){
		if(ni == ncnt || p[pi] < -n[ni])
			sum += p[pi] - cur, cur = p[pi++];
		else sum += cur - n[ni], cur = n[ni++];
	}
	printf("%d\n", ans - (sum > T));

	return 0;
}