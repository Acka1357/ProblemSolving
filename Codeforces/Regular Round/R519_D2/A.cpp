#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, st = 0; scanf("%d", &N);
	long long sum = 0;
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		sum += x;
		st = max(st, x);
	}
	
	long long l = st, r = 10000000, m, ans = -1;
	while(l <= r){
		m = (l + r) / 2;
		if(sum < N * m - sum){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%lld\n", ans);
	
	return 0;
}