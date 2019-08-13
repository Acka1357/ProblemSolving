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

struct Student{
	ll a, b;
	bool operator <(const Student &o)const{
		return o.a - o.b < a - b;
	}
};

Student st[100000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld %lld", &st[i].a, &st[i].b);
	sort(st, st + N);

	ll ans = 0;
	for(int i = 0; i < N; i++)
		ans += st[i].a * i + st[i].b * (N - i - 1);
	printf("%lld\n", ans);

	return 0;
}
