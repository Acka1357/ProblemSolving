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

ll gcd(ll a, ll b){
	ll c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

ll absx(ll x){ return x < 0 ? -x : x; }

struct Num{
	ll x; int idx;
	bool operator <(const Num &o)const{
		return x == o.x ? idx < o.idx : x < o.x;
	}
};

Num a[200003];
ll N;

int main()
{
	scanf("%lld", &N);
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		a[i] = {(ll)x, i};
	}
	if(N <= 3) return !printf("1\n");

	sort(a + 1, a + N + 1);

	ll d1 = a[3].x - a[2].x, d2 = a[3].x - a[1].x;
	bool ans1 = true, ans2 = true;
	for(int i = 4; i <= N; i++){
		if(a[i].x - a[i - 1].x != d1) ans1 = false;
		if(a[i].x - a[i - 1].x != d2) ans2 = false;
	}
	if(ans1 || ans2) return !printf("%d\n", ans1 ? a[1].idx : a[2].idx);

	ll d = a[2].x - a[1].x; int ans = -1;
	for(int i = 3; i <= N; i++)
		if(a[i].x - a[i - 1].x != d){
			if(ans != -1) return !printf("-1\n");
			ans = a[i].idx;
			if(i < N && a[i + 1].x - a[i - 1].x != d)
				return !printf("-1\n");
			i++;
		}
	printf("%d\n", ans < 0 ? a[1].idx : ans);

	return 0;
}
