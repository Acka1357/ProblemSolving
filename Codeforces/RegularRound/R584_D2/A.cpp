#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int a[105];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N);

	int ans = 0;
	for(int i = 0; i < N; i++){
		if(a[i] == 0) continue;
		ans++;
		for(int j = i + 1; j < N; j++)
			if(a[j] && a[j] % a[i] == 0)
				a[j] = 0;
		a[i] = 0;
	}
	printf("%d\n", ans);

	return 0;
}
