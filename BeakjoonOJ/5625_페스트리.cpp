//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int tc, st = 0; for(scanf("%d", &tc); st++ < tc;){
        int N, M; scanf("%d %d", &N, &M);

        vector<vector<int> > adj(N + 1);
        for(int i = 0, u, v; i < M; i++){
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> gen(N + 1, 0);
        bool psb = true;
        for(int i = 1; i <= N && psb; i++) {
            if(gen[i]) continue;

            queue<int> q; q.push(i);
            gen[i] = 1;
            while (!q.empty() && psb) {
                int cur = q.front();
                q.pop();
                for (int i = adj[cur].size() - 1; 0 <= i; i--) {
                    if (gen[adj[cur][i]]) {
                        if (gen[adj[cur][i]] == gen[cur]) {
                            psb = false;
                            break;
                        }
                    }
                    else {
                        gen[adj[cur][i]] = -gen[cur];
                        q.push(adj[cur][i]);
                    }
                }
            }
        }

        printf("Scenario #%d:\n%s\n%s", st, psb ? "No suspicious bugs found!" : "Suspicious bugs found!", st == tc ? "" : "\n");
    }
    return 0;
}
