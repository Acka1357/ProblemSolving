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

const ll mod = 1000000007;

int N, K, par[100001], cnt[100001];

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void link(int px, int py){
	par[py] = px;
	cnt[px] += cnt[py];
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i= 1; i <= N; i++)
		par[i] = i, cnt[i] = 1;
	for(int i = 1, u, v, c; i < N; i++){
		scanf("%d %d %d", &u, &v, &c);
		if(!c) link(find(u), find(v));
	}

	ll ans = 1;
	for(int i = 1; i <= K; i++)
		ans = (ans * N) % mod;

	for(int i = 1; i <= N; i++){
		if(find(i) != i) continue;
		ll sum = 1;
		for(int j = 1; j <= K; j++)
			sum = (sum * cnt[i]) % mod;
		ans = (ans - sum + mod) % mod; 
	}
	printf("%lld\n", ans);

	return 0;
}
