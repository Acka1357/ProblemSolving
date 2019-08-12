#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;

int st[220], si[1 << 12];
ll N, D, L, S, lc[13], d[220], cost[220][220], tmp[220][220];

void mm_min(ll a[][220], ll b[][220], ll ret[][220]){
	memset(tmp, 0x3f, sizeof(tmp));
	for(int k = 0; k < S; k++)
		for(int i = 0; i < S; i++){
			ll c = a[i][k];
			for(int j = 0; j < S; j++)
				tmp[i][j] = min(tmp[i][j], c + b[k][j]);
		}
	for(int i = 0; i < S; i++)
		for(int j = 0; j < S; j++)
			ret[i][j] = tmp[i][j];
}

void mult(ll a[], ll b[][220], ll ret[]){
	memset(tmp[0], 0x3f, sizeof(tmp[0]));
	for(int i = 0; i < S; i++){
		ll &res = tmp[0][i];
		for(int j = 0; j < S; j++)
			res = min(res, a[j] + b[i][j]);
	}
	for(int i = 0; i < S; i++)
		ret[i] = tmp[0][i];
}

int main()
{
	scanf("%lld %lld %lld", &N, &D, &L);
	for(int i = 1; i <= L; i++)
		scanf("%lld", &lc[i]);

	for(int i = 1, ed = (1 << L); i < ed; i++)
		if(__builtin_popcount(i) == N){
			st[S] = i;
			si[i] = S++;
		}

	memset(cost, 0x3f, sizeof(cost));
	memset(d, 0x3f, sizeof(d));
	d[0] = 0;

	for(int i = 0; i < S; i++){
		int cur = st[i], nxt = (cur >> 1);
		if(!(cur & 1)){
			cost[i][si[nxt]] = 0;
			continue;
		}
		for(int j = 1, b = 1; j <= L; j++, b <<= 1)
			if(!(nxt & b)) cost[i][si[nxt | b]] = lc[j];
	}

	for(D -= N; D > 0; D >>= 1){
		if(D & 1) mult(d, cost, d);
		mm_min(cost, cost, cost);
	}	
	printf("%lld\n", d[0]);

	return 0;
}