#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

int a[100000], b[100000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &b[i]);

	sort(a, a + N);
	sort(b, b + N);

	int ai = N - 1, bi = N - 1;
	long long ans = 0;
	for(int i = 0; i < N; i++){
		if(bi < 0 || (ai >= 0 && bi >= 0 && a[ai] >= b[bi]))
			ans += a[ai--];
		else bi--;
		if(ai < 0 || (ai >= 0 && bi >= 0 && b[bi] >= a[ai]))
			ans -= b[bi--];
		else ai--;
	}

	printf("%lld\n", ans);
	return 0;
}
