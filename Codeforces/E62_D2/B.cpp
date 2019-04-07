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

char s[103];
int Q, L;

int main()
{
	for(scanf("%d", &Q); Q--;){
		scanf("%d %s", &L, s);
		int lcnt, rcnt;
		for(lcnt = 0; s[lcnt]; lcnt++)
			if(s[lcnt] == '>') break;
		for(rcnt = 0; rcnt < L; rcnt++)
			if(s[L - rcnt - 1] == '<') break;
		printf("%d\n", min(lcnt, rcnt));
	}
	return 0;
}
