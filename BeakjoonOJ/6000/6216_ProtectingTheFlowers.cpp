#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Cow{
	int t, d;
	bool operator <(const Cow &o)const{
		return t * o.d < o.t * d;
	}
};

Cow cow[100000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &cow[i].t, &cow[i].d);

	sort(cow, cow + N);

	ll ans = 0, t = 0;
	for(int i = 0; i < N; i++){
		ans += cow[i].d * t;
		t += 2 * cow[i].t;
	}
	printf("%lld\n", ans);

	return 0;
}
