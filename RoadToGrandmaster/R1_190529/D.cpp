#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

int a[100];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0, h, m; i < N; i++){
		scanf("%02d:%02d", &h, &m);
		a[i] = h * 60 + m;
	}

	if(N == 1) return !printf("23:59\n");

	sort(a, a + N);

	int ans = 24 * 60 + a[0] - a[N - 1] - 1;
	for(int i = 1; i < N; i++)
		ans = max(ans, a[i] - a[i - 1] - 1);

	printf("%02d:%02d\n", ans / 60, ans % 60);

	return 0;
}
