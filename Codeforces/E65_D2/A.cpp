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

char s[101];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int l; scanf("%d %s", &l, s);
		int st = -1;
		for(int i = 0; i < l; i++)
			if(s[i] == '8'){
				st = i; break;
			}
		printf("%s\n", (st < 0 || st + 11 > l) ? "NO" : "YES");
	}
	return 0;
}
