#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Edge{
	int v, c;
	Edge(int v, int c):v(v), c(c){}
	bool operator <(const Edge &o)const{
		return c > o.c;
	}
};

vector<Edge> adj[5001];
int V, E, mind[5001], sd[5001];

int main()
{
	scanf("%d %d", &V, &E);
	for(int i = 0, u, v, c; i < E; i++){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(Edge(v, c));
		adj[v].push_back(Edge(u, c));
	}

	memset(mind, 0x3f, sizeof(mind));
	memset(sd, 0x3f, sizeof(sd));

	priority_queue<Edge> q; q.push(Edge(1, mind[1] = 0));
	while(!q.empty()){
		int cur = q.top().v, cost = q.top().c; q.pop();
		if(sd[cur] < cost) continue;
		if(cur == V && cost != mind[V]) break;
		for(int i = 0; i < adj[cur].size(); i++){
			int nxt = adj[cur][i].v, newc = cost + adj[cur][i].c;
			if(sd[nxt] < newc) continue;
			if(mind[nxt] > newc){
				sd[nxt] = mind[nxt];
				mind[nxt] = newc;
			}
			else if(mind[nxt] != newc) sd[nxt] = newc;
			q.push(Edge(nxt, newc));
		}
	}
	printf("%d\n", sd[V]);

	return 0;
}
