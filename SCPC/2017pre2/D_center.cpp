//
// Created by Acka on 2017. 7. 15..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
};

vector<Edge> adj[1001];
long long d[1001][1001], maxd[1001], len[1001][1001];
int P, subcnt[1001];

long long leaf_dist(int cur, int par){
    long long maxl = 0;
    for(int i = 0; i < adj[cur].size(); i++){
        int& next = adj[cur][i].to;
        if(next == par) continue;
        long long l = leaf_dist(next, cur) + adj[cur][i].cost;
        len[cur][i] = l;
        maxl = max(maxl, l);
    }
    return maxl;
}

void calc_far(int cur, int par){
    long long max1 = 0, max2 = 0, c1 = -1, c2 = -1;

    for(int i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i].to == par) continue;
        if(len[cur][i] > max1){
            max2 = max1; c2 = c1;
            max1 = len[cur][i]; c1 = i;
        }
        else if(len[cur][i] > max2)
            max2 = len[cur][i]; c2 = i;
    }

    for(int i = 0; i < adj[cur].size(); i++){
        int& next = adj[cur][i].to;
        if(next == par) continue;
        maxd[next] = maxd[cur];
        if(i == c1) maxd[next] = max(maxd[next], max2);
        else maxd[next] = max(maxd[next], max1);
        maxd[next] += adj[cur][i].cost;
        calc_far(next, cur);
    }
}

void calc_sub(int cur, int par){
    subcnt[cur] = 1;

    for(int i = 0; i < adj[cur].size(); i++){
        int& next = adj[cur][i].to;
        if(next == par) continue;

        calc_sub(next, cur);
        subcnt[cur] += subcnt[next];
//        printf("[p:%d c:%d]\n", cur, next);

        for(int p = min(subcnt[cur], P); p >= 1; p--){
            if(p > 1) d[cur][p] = max(d[cur][p], d[next][1] + adj[cur][i].cost);
            long long nouse = d[cur][p];
            for(int j = min(subcnt[next], p - 1); j > 0; j--) {
                long long newc = max(d[cur][p - j], d[next][j]);
//                printf("pcnt:%d ccnt:%d, p:%lld c:%lld no:%lld new:%lld", p - j, j, d[cur][p - j], d[next][j], nouse, newc);
                if(nouse > newc && d[cur][p] > newc) d[cur][p] = nouse = newc;
//                printf(" d[%d][%d]: %lld\n", cur, p, d[cur][p]);
            }

        }
        d[cur][1] = max(d[cur][1], d[next][1] + adj[cur][i].cost);
    }
}


int main()
{
    setbuf(stdout, NULL);
    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N; scanf("%d", &N);
        if(N > 1000){
            for(int i = 1; i < N; i++) scanf("%*d %*d %*d");
            scanf("%*d");
            printf("Case #%d\n%lld\n", tc, -1);
            continue;
        }

        memset(d, 0, sizeof(d));
        for(int i = 1; i <= N; i++)
            adj[i].clear();

        for(int i = 1, u, v, w; i < N; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(Edge(v, w));
            adj[v].push_back(Edge(u, w));
        }

        scanf("%d", &P);
        leaf_dist(1, 0);
        calc_far(1, 0);
        calc_sub(1, 0);

        long long ans = max(d[1][P], maxd[1]);
//        printf("%d: %lld %lld\n", 1, d[1][P], maxd[1]);
        for(int i = 2; i <= N; i++)
            if(subcnt[i] >= P){
                ans = min(ans, max(d[i][P], maxd[i]));
//                printf("%d: %lld %lld\n", i, d[i][P], maxd[i]);
            }

        printf("Case #%d\n%lld\n", tc, ans);
    }
    return 0;
}
