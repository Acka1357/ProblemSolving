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

struct Point{ ll x, y;
	bool operator <(const Point &o) const{ return x == o.x ? y < o.y : x < o.x; }
};
struct Crd{ int r, c; };
struct Edge{ int to, cost; };
struct Node{ int cur; ll cost;
	bool operator <(const Node &o)const{ return cost > o.cost; }
};

char a[100001], b[100001], s[100001];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%s %s", a, b);
		int al = strlen(a), bl = strlen(b);
		int bi = 0, ans = 0;
		for(int i = bl - 1; i >= 0; i--, bi++)
			if(b[i] == '1') break;
		// printf(" - %d\n", bi);
		for(int j = al - bi - 1; j >= 0; j--, ans++)
			if(a[j] == '1') break;
		printf("%d\n", ans);
	}
	return 0;
}
