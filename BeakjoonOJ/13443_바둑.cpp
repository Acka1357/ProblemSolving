//
// Created by Acka on 10/28/16.
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

char map[50][51];

int main()
{
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

    int N, sum = 0; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    BTM btm(N * N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(map[i][j] != 'x') sum++;
            if(map[i][j] != 'o') continue;
            for(int k = 0; k < 4; k++){
                int nr = i + dr[k], nc = j + dc[k];
                if(nr < 0 || nc < 0 || N <= nr || N <= nc) continue;
                if(map[nr][nc] == '.')
                    btm.add_edge(i * N + j, nr * N + nc);
            }
        }

    printf("%d\n", sum - btm.maxbtm());
    return 0;
}
