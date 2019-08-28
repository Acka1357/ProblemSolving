#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll d[100005], tmax1, tmax2, c1, c2;
int c[100005], v[100005];

int main()
{
	int N, Q; scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &c[i]);

	while(Q--){
		ll a, b; scanf("%lld %lld", &b, &a);

		tmax1 = tmax2 = c1 = c2 = 0;
		memset(d, 0xbf, sizeof(d));
		for(int i = 0; i < N; i++){
			d[c[i]] = max({d[c[i]], d[c[i]] + b * v[i], (c1 == c[i] ? tmax2 : tmax1) + a * v[i]});
			if(c1 == c[i]) tmax1 = d[c[i]];
			else if(d[c[i]] > tmax1){
				tmax2 = tmax1; c2 = c1;
				tmax1 = d[c[i]]; c1 = c[i];
			}
			else if(d[c[i]] > tmax2) tmax2 = d[c[i]], c2 = c[i];
		}
		printf("%lld\n", tmax1);
	}
	return 0;
}