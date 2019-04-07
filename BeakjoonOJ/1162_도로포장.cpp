#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

struct Edge{ int to, cost; };

struct Node{
    int cur, cnt; ll cost;
    bool operator <(const Node &o)const{
        return cost > o.cost;
    }
};

ll mind[21][10001];
vector<Edge> adj[10001];

int main()
{
    int V, E, K; scanf("%d %d %d", &V, &E, &K);
    for(int i = 0, u, v, c; i < E; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    memset(mind, 0x3f, sizeof mind);
    priority_queue<Node> q;
    q.push({1, 0, mind[0][1] = 0});
    while(!q.empty()){
        int cur = q.top().cur, cnt = q.top().cnt; ll cost = q.top().cost; q.pop();
        if(mind[cnt][cur] < cost) continue;
        if(cur == V) return printf("%lld\n", cost) & 0;
        for(Edge &e : adj[cur]){
            ll nc = cost + e.cost;
            if(mind[cnt][e.to] > nc)
                q.push({e.to, cnt, mind[cnt][e.to] = nc});
            if(cnt < K && mind[cnt + 1][e.to] > cost)
                q.push({e.to, cnt + 1, mind[cnt + 1][e.to] = cost});
        }
    }

    return 0;
}
