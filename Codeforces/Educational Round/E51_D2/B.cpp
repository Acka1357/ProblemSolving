#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{
	long long l, r; scanf("%lld %lld", &l, &r);
	printf("YES\n");
	for(long long i = l; i <= r; i += 2)
		printf("%lld %lld\n", i, i + 1);
	return 0;
}
