#include <cstdio>
#include <algorithm>
using namespace std;

int a[20000];

int main()
{
	int N, S, ans = 0; scanf("%d %d", &N, &S);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	sort(a, a + N);
	
	for(int i = 0, r = N - 1; i < N; i++){
		while(a[i] + a[r] > S && r > i) r--;
		ans += max(r, i) - i;
	}
	printf("%d\n", ans);

	return 0;
}