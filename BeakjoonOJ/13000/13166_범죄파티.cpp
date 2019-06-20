//
// Created by Acka on 10/1/16.
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

int N, a[200001][4];
bool psb_matching(int x){
    BTM btm(3 * N + 1);
    for(int i = 1; i <= N; i++){
        if(a[i][1] <= x) btm.add_edge(i, N + a[i][0]);
        if(a[i][3] <= x) btm.add_edge(i, N + a[i][2]);
    }
    return btm.maxbtm() == N;
}

int main()
{
    scanf("%d", &N);

    int l = 0, r = 0, m, ans = -1;
    for(int i = 1; i <= N; i++) {
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        l = max(l, min(a[i][1], a[i][3]));
        r = max(r, max(a[i][1], a[i][3]));
    }

    while (l <= r) {
        m = (l + r) / 2;

        if (psb_matching(m)) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}
