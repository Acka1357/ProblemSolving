#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
    bool operator <(const Edge &o)const{
        return o.cost < cost;
    }
};

int N, M, X, mind[1001], sum[1001];

void dijkstra(vector<vector<Edge> >& adj){
    memset(mind, 0x3f, sizeof(mind));
    priority_queue<Edge> q;
    q.push(Edge(X, mind[X] = 0));
    while(!q.empty()){
        int cur = q.top().to, cost = q.top().cost; q.pop();
        if(mind[cur] < cost) continue;
        for(Edge &e : adj[cur]){
            if(cost + e.cost < mind[e.to]){
                q.push(Edge(e.to, cost + e.cost));
                mind[e.to] = cost + e.cost;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    	sum[i] += mind[i];
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);

    vector<vector<Edge> > adj(N + 1), rev(N + 1);
    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
        rev[v].push_back(Edge(u, c));
    }

    dijkstra(adj);
    dijkstra(rev);

    int ans = sum[1];
    for(int i = 2; i <= N; i++)
        ans = max(ans, sum[i]);
    printf("%d\n", ans);
    
    return 0;
}
