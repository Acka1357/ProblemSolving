//
// Created by Acka on 11/2/16.
//

#include <stdio.h>
#include <vector>
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

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    BTM btm(2 * N);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        btm.add_edge(u - 1, N + v - 1);
    }

    printf("%d\n", N - btm.maxbtm());
    return 0;
}

