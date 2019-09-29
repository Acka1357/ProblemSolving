#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

vector<int> adj[300005];
int e1[300005], e2[300005], cnt12, cnt23, cnt31;
int clr[300005]; // 1(6):110 2(5):101 3(3):011

int main()
{
	int V, E; scanf("%d %d", &V, &E);
	for(int i = 0, u, v; i < E; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		e1[i] = u, e2[i] = v;
	}

	for(int i = 1; i <= V; i++)
		if(adj[i].size() < 2)
			return !printf("-1\n");

	clr[1] = 6; clr[adj[1][0]] = 5;
	queue<int> q;
	q.push(1); q.push(adj[1][0]);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		int tog = clr[cur] ^ 7;
		for(int &nxt : adj[cur]){
			if(clr[nxt]){
				if(__builtin_popcount(clr[nxt]) == 2){
					if((clr[nxt] & tog) != tog) return !printf("-1\n");
				}
				else if(!(clr[nxt] & tog)){
					clr[nxt] |= tog;
					q.push(nxt);
				}
			}
			else clr[nxt] |= tog;
		}
	}

	for(int i = 1; i <= V; i++)
		if(__builtin_popcount(clr[i]) != 2)
			return !printf("-1\n");

	ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1; i <= V; i++){
		if(clr[i] == 6) cnt1++;
		else if(clr[i] == 5) cnt2++;
		else cnt3++;
	}
	if(!cnt1 || !cnt2 || !cnt3) return !printf("-1\n");

	for(int i = 0; i < E; i++){
		int u = e1[i], v = e2[i];
		if((clr[u] & clr[v]) == 4) cnt12++;
		else if((clr[u] & clr[v]) == 1) cnt23++;
		else cnt31++;
	}

	if(cnt1 * cnt2 != cnt12) return !printf("-1\n");
	if(cnt2 * cnt3 != cnt23) return !printf("-1\n");
	if(cnt3 * cnt1 != cnt31) return !printf("-1\n");

	for(int i = 1; i <= V; i++)
		printf("%d%c", clr[i] == 3 ? 3 : (clr[i] == 6 ? 1 : 2), " \n"[i == V]);

	return 0;
}