#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <cassert>
using namespace std;

typedef long long ll;

struct Info{
	int from, to; ll x;
	bool operator <(const Info &o)const{
		return from < o.from;
	}
};

vector<ll> bucket[17];
map<ll, int> has;
ll sum[17], tot, T;
vector<Info> comp[1 << 16], cinfo;
bool chk[17];

void trans(int S, ll sx, int bi, ll x, int st){
	if(chk[bi] && S == bi){
		if(x == sx) comp[st] = cinfo;
		return ;
	}

	auto ret = has.find(T - (sum[bi] - x));
	if(ret == has.end()) return ;

	sum[bi] -= x;
	ll val = ret->first;
	int from = ret->second;
	if(!chk[from]){
		chk[from] = true;
		sum[bi] += val;
		cinfo.push_back({from, bi, val});
		trans(S, sx, from, val, st | (1 << (bi - 1)));
		cinfo.pop_back();
		chk[from] = false;
		sum[bi] -= val;
	}
	sum[bi] += x;
}

int main()
{
	ll K; scanf("%lld", &K);
	for(int i = 1; i <= K; i++){
		int N; scanf("%d", &N);
		for(int j = 0; j < N; j++){
			ll x; scanf("%lld", &x);
			bucket[i].push_back(x);
			tot += x;
			sum[i] += x;
			has[x] = i;
		}
	}

	if(tot % K) return !printf("No\n");

	T = tot / K;
	for(int i = 1; i <= K; i++){
		if(chk[i]) continue;
		for(ll x : bucket[i])
			trans(i, x, i, x, 0);
	}

	int all = (1 << K) - 1;
	for(int i = 1; i <= all; i++){
		if(comp[i].size()) continue;
		for(int st = i; st; st = (st - 1) & i)
			if(comp[st].size() && comp[i ^ st].size()){
				comp[i] = comp[st];
				for(Info &info : comp[i ^ st])
					comp[i].push_back(info);
				break;
			}
	}

	if(!comp[all].size()) return !printf("NO\n");
	
	sort(comp[all].begin(), comp[all].end());

	printf("Yes\n");
	for(Info &info : comp[all])
		printf("%lld %d\n", info.x, info.to);

	return 0;
}