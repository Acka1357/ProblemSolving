// solution:
// 지불할 비용 fc를 결정하고, 이것만큼만 지불해서 가능한지를 판단하는 binary search를 진행.
// fc보다 비싼 케이블을 K개 이하로 사용해서 1번과 N번을 연결할 수 있다면 가능.
// 이 부분은 다익스트라로 해결.

// 시간복잡도: O(log(Pmax) * P);
// 분류: Binary Search, Shortest Path
// 난이도: 1750

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct Edge{ int v, c; };
struct Node{
	int cur, cost;
	bool operator <(const Node &o)const{
		return cost > o.cost;
	}
};

int N, E, K, mind[1001];
vector<Edge> adj[1001];

bool psb(int fc){
	memset(mind, 0x3f, sizeof(mind));
	priority_queue<Node> q;
	q.push({1, mind[1] = 0});
	while(!q.empty()){
		int cur = q.top().cur, cost = q.top().cost; q.pop();
		if(mind[cur] < cost) continue;
		for(Edge &e : adj[cur]){
			int nc = cost + (e.c > fc);
			if(nc <= K && mind[e.v] > nc){
				if(e.v == N) return true;
				q.push({e.v, mind[e.v] = nc});
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &N, &E, &K);
	for(int i = 0, u, v, c; i < E; i++){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	int l = 0, r = 1000000, m, ans = -1;
	while(l <= r){
		m = (l + r) / 2;
		if(psb(m)) r = m - 1, ans = m;
		else l = m + 1;
	}
	printf("%d\n", ans);

	return 0;
}