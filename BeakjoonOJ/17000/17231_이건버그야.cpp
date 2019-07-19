#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned int uint;

struct Node{ uint scr, sum, con, sep, l; };
struct Ex{ int par; uint sum, con, sep, l; };

int t, ts[100001];
vector<int> adj[100001];
Node v[100001];
Ex ex[100001], up[100001];

void dfs(int idx, int par){
	Node &cur = v[idx];
	ts[++t] = idx, ex[idx].par = par;

	uint l1 = 0, l2 = 0; int li1 = 0, li2 = 0;
	for(int &nxt : adj[idx])
		if(nxt != par){
			dfs(nxt, idx);
			if(v[nxt].l > l1){
				l2 = l1, li2 = li1;
				l1 = v[nxt].l, li1 = nxt;
			}
			else if(v[nxt].l > l2)
				l2 = v[nxt].l, li2 = nxt;
		}

	cur.con = (cur.sum = cur.scr) * (l1 + 1);
	cur.l = l1 + 1;
	
	uint sv1 = 0, sv2 = 0;
	for(int &nxt : adj[idx]){
		if(nxt == par) continue;
		cur.sum += v[nxt].sum;
		cur.con += v[nxt].con + v[nxt].sum * (l1 - v[nxt].l); 
		cur.sep = max({cur.sep, v[nxt].con, v[nxt].sep});
		
		uint sv = max(v[nxt].con, v[nxt].sep);
		if(sv > sv1) { sv2 = sv1; sv1 = sv; }
		else if(sv > sv2) sv2 = sv;

		if(nxt != li1){
			ex[li1].sum += v[nxt].sum;
			ex[li1].con += v[nxt].con + v[nxt].sum * (l2 - v[nxt].l);
			ex[li1].sep = max({ex[li1].sep, v[nxt].con, v[nxt].sep});
		}
	}

	ex[li1].l = l2 + 1;
	ex[li1].sum += cur.scr;
	ex[li1].con += cur.scr * (l2 + 1);

	for(int &nxt : adj[idx]){
		if(nxt == par || nxt == li1) continue;
		if(max(v[nxt].con, v[nxt].sep) == sv1) ex[nxt].sep = sv2;
		else ex[nxt].sep = sv1;
		ex[nxt].sum = cur.sum - v[nxt].sum;
		ex[nxt].con = cur.con - v[nxt].con - v[nxt].sum * (l1 - v[nxt].l);
		ex[nxt].l = l1 + 1;
	}
}

ll ans[100001];

int main()
{
	int N, Q; scanf("%d %d", &N, &Q);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= N; i++)
		scanf("%u", &v[i].scr);

	dfs(1, 0);

	memset(ans, 0xbf, sizeof(ans));
	for(int &ch : adj[1])
		ans[1] = max({ans[1], (ll)v[ch].con - ex[ch].con, (ll)v[ch].sep - ex[ch].con});

	for(int i = 2; i <= N; i++){
		int cur = ts[i], par = ex[cur].par;

		up[cur].l = max(up[par].l + 1u, ex[cur].l);
		up[cur].sum = up[par].sum + ex[cur].sum;
		up[cur].con = up[par].con + ex[cur].con + up[par].sum * (up[cur].l - up[par].l - 1u) + ex[cur].sum * (up[cur].l - ex[cur].l);
		up[cur].sep = max({ex[cur].sep, up[par].sep, up[par].con});

		for(int &ch : adj[cur]){
			if(ch != par){
				uint len = max(ex[ch].l, up[cur].l + 1u);
				uint scon = ex[ch].con + up[cur].con + ex[ch].sum * (len - ex[ch].l) + up[cur].sum * (len - up[cur].l - 1u);
				ans[cur] = max(ans[cur], (ll)max(v[ch].con, v[ch].sep) - scon);
			}
			else ans[cur] = max(ans[cur], (ll)max({up[cur].con, up[cur].sep, ex[cur].sep}) - v[cur].con);
		}
	}

	while(Q--){
		int q; scanf("%d", &q);
		printf("%lld\n", ans[q]);
	}

	return 0;
}