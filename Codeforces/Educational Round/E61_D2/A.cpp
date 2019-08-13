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

ll c1, c2, c3, c4, cur;

int main()
{
	scanf("%lld %lld %lld %lld", &c1, &c2, &c3, &c4);
	if((!c1 && c3) || c1 != c4) return !printf("0\n");
	printf("1\n");
	
	return 0;
}
