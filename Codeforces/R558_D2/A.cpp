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

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	if(M <= N / 2) printf("%d\n", max(1, M));
	else printf("%d\n", max(0, N - (N / 2) - (M - (N / 2))));
	return 0;
}
