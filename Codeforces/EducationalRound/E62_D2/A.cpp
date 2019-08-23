#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

int N, a[10001];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	int ans = 0, last = 0;
	for(int i = 1; i <= N; i++){
		if(last < i) ans++;
		last = max(last, a[i]);
	}
	printf("%d\n", ans);

	return 0;
}
