#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

struct Info{
	int mcnt; ll msum;
	map<int, int> cnt;
};

ll ans[100005];
Info infos[100005];
vector<int> adj[100005];

Info* merge(Info *dst, Info *src){
	int &mcnt = dst->mcnt; ll &msum = dst->msum;
	map<int, int> &cnt = dst->cnt;
	for(auto it : src->cnt){
		int ccnt = (cnt[it.first] += it.second);
		if(ccnt > mcnt) msum = it.first, mcnt = ccnt;
		else if(ccnt == mcnt) msum += it.first;
	}
	return dst;
}

Info* dfs(int cur, int par){
	Info *sub = &infos[cur];
	for(int &nxt : adj[cur]){
		if(nxt == par) continue;
		Info *ret = dfs(nxt, cur);
		if(sub->cnt.size() < ret->cnt.size())
			sub = merge(ret, sub);
		else sub = merge(sub, ret);
	}
	ans[cur] = sub->msum;
	return sub;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, c; i <= N; i++){
		scanf("%d", &c);
		infos[i].mcnt = 1;
		infos[i].msum = c;
		infos[i].cnt[c]++;
	}

	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	for(int i = 1; i <= N; i++)
		printf("%lld%c", ans[i], " \n"[i == N]);

	return 0;
}