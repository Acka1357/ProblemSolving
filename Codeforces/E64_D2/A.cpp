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
using namespace std;

typedef long long ll;

int a[101];
int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for(int i = 1; i < N; i++){
		if(a[i] + a[i - 1] == 5) return !printf("Infinite\n");
		if(a[i] == 2 || a[i - 1] == 2) ans += 3;
		else ans += 4;
		if(i > 1 && a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3) ans--;
	}
	printf("Finite\n%d\n", ans);

	return 0;
}
