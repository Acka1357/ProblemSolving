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

ll gcd(ll a, ll b){
	ll c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

ll xs[300001], ps[300001];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%lld", &xs[i]);
	for(int i = 0; i < M; i++)
		scanf("%lld", &ps[i]);

	ll g = xs[1] - xs[0];
	for(int i = 2; i < N; i++)
		g = gcd(g, xs[i] - xs[i - 1]);

	for(int i = 0; i < M; i++)
		if(g % ps[i] == 0)
			return !printf("YES\n%lld %d\n", xs[0], i + 1);

	return !printf("NO\n");
}
