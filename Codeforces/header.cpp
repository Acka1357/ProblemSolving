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


int main()
{

	return 0;
}
