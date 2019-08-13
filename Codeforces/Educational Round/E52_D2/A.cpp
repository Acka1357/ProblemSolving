#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--){
		long long S, A, B, C; scanf("%lld %lld %lld %lld", &S, &A, &B, &C);
		long long ans = S / C;
		printf("%lld\n", ans + (ans / A) * B);
	}
	return 0;
}
