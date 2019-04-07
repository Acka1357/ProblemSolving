//
// Created by Acka on 10/4/16.
//

#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

struct BTM{
    int N, step;
    vector<vector<int> > G;
    vector<int> match, used;

    BTM(int N): N(N), G(N), match(vector<int>(N, -1)), used(N), step(0){}

    void add_edge(int l, int r){ G[l].push_back(r); }

    bool dfs(int v){
        used[v] = step;
        for (int i = 0; i < G[v].size(); i++){
            int u = G[v][i], w = match[u];
            if (w < 0 || used[w] != step && dfs(w)){
                match[v] = u; match[u] = v;
                return true;
            }
        }
        return false;
    }

    int maxbtm(){
        int sum = 0;
        for (int v = 0; v < N; v++){
            if (match[v] == -1){
                ++step;
                if (dfs(v)) sum++;
            }
        }
        return sum;
    }
};

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){};
};

int mind[12][12], N, M, man_cnt, exit_cnt;
vector<Edge> adj[12 * 12];

bool psb_matching(int x){
    BTM btm(N * M + x * exit_cnt);
    for(int i = 0; i < N * M; i++)
        for (int j = 0; j < adj[i].size(); j++)
            if(adj[i][j].cost <= x) {
                for(int k = adj[i][j].cost; k <= x; k++)
                    btm.add_edge(i, N * M + (x * adj[i][j].to) + k - 1);
            }

    return btm.maxbtm() == man_cnt;
}

int main()
{
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

    scanf("%d %d", &N, &M);

    char map[12][13];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(map[i][j] != 'D'){
                if(map[i][j] == '.') man_cnt++;
                continue;
            }

            memset(mind, 0xff, sizeof(mind));
            queue<int> q; q.push(i * M + j);
            mind[i][j] = 0;
            while(!q.empty()){
                int r = q.front() / M, c = q.front() % M; q.pop();
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k], nc = c + dc[k];
                    if(nr < 0 || nc < 0 || N <= nr || M <= nc) continue;
                    if(0 <= mind[nr][nc] || map[nr][nc] != '.') continue;
                    adj[nr * M + nc].push_back(Edge(exit_cnt, mind[nr][nc] = (mind[r][c] + 1)));
                    q.push(nr * M + nc);
                }
            }
            exit_cnt++;
        }

    int l = 0, r = N * M, m, ans = -1;
    while (l <= r) {
        m = (l + r) / 2;

        if (psb_matching(m)) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    if(ans < 0) printf("impossible\n");
    else printf("%d\n", ans);

    return 0;
}
