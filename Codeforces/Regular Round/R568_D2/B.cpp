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

char a[1000001], b[1000001];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%s %s", a, b);

		bool psb = (a[0] == b[0]);
		int ai, bi;
		for(ai = 0, bi = 0; b[bi] && psb; bi++){
			if(a[ai] == b[bi]) ai++;
			else if(a[ai - 1] != b[bi]) psb = false;
		}
		printf("%s\n", (psb && !a[ai])? "YES" : "NO");
	}
	return 0;
}
