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
	int N, L, R; scanf("%d %d %d", &N, &L, &R);

	int mn = 0, mx = 0, min_cnt = N - L, max_cnt = N - R;
	for(int i = 1, b = 1; i <= L; i++, b <<= 1)
		mn += b;
	mn += min_cnt;

	int b = 1;
	for(int i = 1; i <= R; i++, b <<= 1)
		mx += b;
	mx += max_cnt * (b / 2);

	printf("%d %d\n", mn, mx);

	return 0;
}