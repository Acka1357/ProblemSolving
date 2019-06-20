//
// Created by Acka on 4/25/16.
//

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Info{
    int x, d, past;
    Info(){} Info(int x, int d, int p):x(x), d(d), past(p){}
    bool operator <(const Info &A)const{
        return A.d < d;
    }
};

int N, M, S, D, mind[500], adj[500][500];
vector<int> past[500];

int dijkstra(bool find_all){
    priority_queue<Info> pq;
    pq.push(Info(S, 0, -1));

    memset(mind, 0x3f, sizeof(mind));
    mind[S] = 0;

    int ret = -1, x, d, cd, px;
    while(!pq.empty()){
        x = pq.top().x; d = pq.top().d; px = pq.top().past; pq.pop();

        if(x == D && mind[x] < d) break;
        if(mind[x] < d) continue;
        if(find_all) past[x].push_back(px);

        if(x == D){
            if(ret < 0) ret = d;
            if(!find_all) break;
        }

        for(int i = 0; i < N; i++) {
            cd = d + adj[x][i];
            if (adj[x][i] && ((cd < mind[i]) || (find_all && (cd == mind[i])))) {
                if (find_all && cd < mind[i]) past[i].clear();
                if(cd < mind[i] || (find_all && (cd == mind[i]))) pq.push(Info(i, cd, x));
                mind[i] = cd;
            }
        }
    }
    return ret;
}

void clear_path(int cur){
    if(cur == S) return ;
    for(int i = past[cur].size() - 1; 0 <= i; i--)
        if(adj[past[cur][i]][cur]) {
            adj[past[cur][i]][cur] = 0;
            clear_path(past[cur][i]);
        }
    past[cur].clear();
}

int main()
{
    while(scanf("%d %d", &N, &M)){
        if(!N && !M) break;

        memset(adj, 0, sizeof(adj));

        scanf("%d %d", &S, &D);
        for(int i = 0, u, v, c; i < M; i++){
            scanf("%d %d %d", &u, &v, &c);
            adj[u][v] = c;
        }

        dijkstra(true);
        clear_path(D);
        printf("%d\n", dijkstra(false));
    }

    return 0;
}

