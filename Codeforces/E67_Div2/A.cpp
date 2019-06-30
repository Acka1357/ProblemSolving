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
	int tc; for(scanf("%d", &tc); tc--;){
		int N, S, T; scanf("%d %d %d", &N, &S, &T);
		printf("%d\n", N - min(S, T) + 1);
	}
	return 0;
}
