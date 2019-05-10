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

const int BASE = 20000;

ll gcd(ll a, ll b){
	ll c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

bool xchk[BASE * 2 + 1], ychk[BASE * 2 + 1];
int x[1001], y[1001];
set<pair<int, pair<int, int>>> s;

ll calc(ll cnt){
	return (cnt * (cnt - 1)) / 2;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &y[i]);

	ll xcnt = 0, ycnt = 0, cnt = 0;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++){
			int dx = x[j] - x[i];
			int dy = y[j] - y[i];

			if(dx == 0){
				if(!xchk[x[i] + BASE]) xcnt++;
				xchk[x[i] + BASE] = true;
				continue;
			}
			else if(dy == 0){
				if(!ychk[y[i] + BASE]) ycnt++;
				ychk[y[i] + BASE] = true;
				continue;
			}

			int g = gcd((dx < 0 ? -dx : dx), (dy < 0 ? -dy : dy));
			dx /= g; dy /= g;
			int a = dy, b = -dx, c = -dy * x[i] + dx * y[i];
			if(a < 0) a *= -1, b *= -1, c *= -1;
			if(!s.count({a, {b, c}})){
				s.insert({a, {b, c}});
				cnt++;
			}
		}

	ll ans = calc(xcnt + ycnt + cnt) - calc(xcnt) - calc(ycnt);
	map<pair<int, int>, int> m;
	for(auto it = s.begin(); it != s.end(); it++)
		m[{it->first, it->second.first}]++;
	for(auto it = m.begin(); it != m.end(); it++)
		ans -= calc(it->second);
	printf("%lld\n", ans);
	
	return 0;
}
