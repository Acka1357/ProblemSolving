#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll d[100000], x, y;

int main()
{
	int N, K, P; scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		for(scanf("%d", &P); P--;){
			scanf("%lld %lld", &x, &y);
			d[i] = max(d[i], x * x + y * y);
		}
	
	sort(d, d + N);
	printf("%lld.00\n", d[K - 1]);

	return 0;
}