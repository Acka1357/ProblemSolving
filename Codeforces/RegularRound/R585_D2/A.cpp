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

typedef long long ll;

int main()
{
	int A1, A2, K1, K2, N; scanf("%d %d %d %d %d", &A1, &A2, &K1, &K2, &N);
	int vmin = A1 + A2, vmax = 0;
	for(int i = 0; i <= N; i++){
		if(A1 * K1 < i || A2 * K2 < N -i) continue;
		int r1 = i - A1 * (K1 - 1);
		int r2 = N - i - A2 * (K2 - 1);
		vmin = min(vmin, max(r1, 0) + max(r2, 0));
		vmax = max(vmax, i / K1 + (N - i) / K2);
	}
	printf("%d %d\n", vmin, vmax);

	return 0;
}