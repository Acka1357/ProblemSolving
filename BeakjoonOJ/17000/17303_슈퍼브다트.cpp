/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - dart
	Time Complexity: O(MlogM)
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point{ ll x, y;
	bool operator ==(const Point &o)const{
		return x == o.x && y == o.y;
	}
};
struct Seg{ int ai, bi; };

int par[200001];
vector<int> adj[100001];
Seg seg[200001];
Point ps[100001];

ll ccw(Point &a, Point &b, Point &c){
	return a.x * b.y + b.x * c.y + c.x * a.y
				 - (a.x * c.y + b.x * a.y + c.x * b.y);
};

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x])); 
}

void link(int x, int y){
	par[find(y)] = find(x);
}

int main()
{
	int V, E, S = 0; scanf("%d %d", &V, &E);
	for(int i = 1; i <= V; i++)
		scanf("%lld %lld", &ps[i].x, &ps[i].y);

	for(int i = 1, u, v; i <= E; i++){
		scanf("%d %d", &u, &v);
		seg[++S] = {u, v}; seg[++S] = {v, u};
		adj[u].push_back(S - 1); adj[u].push_back(S);
		adj[v].push_back(S - 1); adj[v].push_back(S);
	}

	for(int i = 1; i <= S; i++) par[i] = i;
	for(int i = 1; i <= V; i++){
		Point &O = ps[i];
		sort(adj[i].begin(), adj[i].end(),
			 [&](const int &a, const int &b){
			 	Point &A = ps[seg[a].ai == i ? seg[a].bi : seg[a].ai];
			 	Point &B = ps[seg[b].ai == i ? seg[b].bi : seg[b].ai];
			 	if(A == B) return seg[a].ai == i;
			 	if((A.y < O.y) != (B.y < O.y)) return A.y >= O.y;
			 	ll val = ccw(O, A, B);
			 	return val ? (val > 0) : (A.x > B.x); });
		for(int j = 0; j < adj[i].size(); j += 2)
			link(adj[i][j], adj[i][j ? j - 1 : adj[i].size() - 1]);
	}

	vector<ll> ans;
	vector<vector<int>> poly(S + 1);
	for(int i = 1; i <= S; i++) poly[find(i)].push_back(i);

	for(vector<int> &pseg : poly){
		ll area = 0;
		for(int &si : pseg){
			Point &a = ps[seg[si].ai], &b = ps[seg[si].bi]; 
			area += (a.x + b.x) * (a.y - b.y);
		}
		if(area > 0) ans.push_back(area);
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(ll v : ans)
		printf("%lld.%d\n", v / 2, v & 1 ? 5 : 0);

	return 0;
}