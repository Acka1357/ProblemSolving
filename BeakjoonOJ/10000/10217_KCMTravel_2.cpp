#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge{ int to, cost, dist; };

const int INF = 0x3f3f3f3f;

vector<Edge> adj[101];
int N, M, K, mind[101][10001];

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

        int ans = INF;
        memset(mind, 0x3f, sizeof(mind));
        mind[1][0] = 0;
        for(int i = 0; i <= M; i++){
            for(int v = 1; v < N; v++){
                if(mind[v][i] == INF) continue;
                for(Edge &e : adj[v]){
                    if(i + e.cost > M) continue;
                    mind[e.to][i + e.cost] = min(mind[e.to][i + e.cost], mind[v][i] + e.dist);
                }
            }
            ans = min(ans, mind[N][i]);
        }

        if(ans == INF) printf("Poor KCM\n");
        else printf("%d\n", ans);
    }
    return 0;
}
