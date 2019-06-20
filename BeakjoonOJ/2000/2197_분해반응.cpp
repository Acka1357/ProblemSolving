#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

int d[151][151], N, M, ans = 987654321;
vector<int> adj[151];

void get_cost(int cur, int par){
    vector<int> child;
    for(int i = adj[cur].size() - 1; 0 <= i; i--)
        if(adj[cur][i] != par){
            get_cost(adj[cur][i], cur);
            child.push_back(adj[cur][i]);
        }

    int ccnt = child.size();
    d[cur][1] = ccnt;
    if(!ccnt){
        if(0 <= d[cur][M]) ans = min(ans, d[cur][M] + (par != 0));
        return;
    }

    vector<int> mind(M + 1, -1);
    for(int i =  child.size() - 1; 0 <= i; i--) {
        for (int j = 1; j <= M; j++) {
            if(d[cur][j] < 0) continue;
            for (int k = 1; k <= M - j; k++) {
                if(d[child[i]][k] < 0) continue;
                    if(mind[j + k] < 0) mind[j + k] = d[cur][j] + d[child[i]][k] - 1;
                    else mind[j + k] = min(mind[j + k], d[cur][j] + d[child[i]][k] - 1);
                }
            }

        for(int j = 1; j <= M; j++)
            if (0 <= mind[j]) d[cur][j] = (d[cur][j] < 0 ? mind[j] : min(d[cur][j], mind[j]));
    }

    if(0 <= d[cur][M]) ans = min(ans, d[cur][M] + (par != 0));
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1, u, v; i < N; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            d[i][j] = -1;

    get_cost(1, 0);
    printf("%d\n", ans);
    return 0;
}

