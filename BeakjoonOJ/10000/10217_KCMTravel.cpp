#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge{ int to, cost, dist; };
struct Node{
    int cur, cost, dist;
    bool operator <(const Node &o)const{
        return dist == o.dist ? cost > o.cost : dist > o.dist;
    }
};

vector<Edge> adj[101];
int N, M, K, mind[101][10001], ts[101][10001];

int main()
{
    int T; scanf("%d", &T);
    for(int tc = 0; tc++ < T;){
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 1; i <= N; i++)
            adj[i].clear();
        for(int i = 0, u, v, c, d; i < K; i++){
            scanf("%d %d %d %d", &u, &v, &c, &d);
            adj[u].push_back({v, c, d});
        }

        bool chk = false;
        priority_queue<Node> q;
        q.push({1, 0, mind[1][0] = 0});
        ts[1][0] = tc;
        while(!q.empty()){
            int cur = q.top().cur, cost = q.top().cost, dist = q.top().dist; q.pop();
            if(cur == N){
                chk = true;
                printf("%d\n", dist);
                break;
            }
            if(mind[cur][cost] < dist) continue;
            for(Edge &e : adj[cur]){
                int nxt = e.to, newc = cost + e.cost, newd = dist + e.dist;
                if(newc > M) continue;
                if(ts[nxt][newc] == tc && mind[nxt][newc] <= newd) continue;
                for(int i = newc; i <= M; i++){
                    if(ts[nxt][i] == tc && mind[nxt][i] <= newd) break;
                    mind[nxt][i] = newd;
                    ts[nxt][i] = tc;
                }
                q.push({nxt, newc, newd});
            }
        }
        if(!chk) printf("Poor KCM\n");
    }
    return 0;
}
