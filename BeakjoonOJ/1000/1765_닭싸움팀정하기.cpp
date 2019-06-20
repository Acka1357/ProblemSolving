//
// Created by Acka on 7/30/16.
//

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int t[1001];
vector<int> f[1001], e[1001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    int u, v; char c;
    for(int i = 0; i < M; i++){
        scanf(" %c %d %d", &c, &u, &v);
        if(c == 'E'){
            e[u].push_back(v);
            e[v].push_back(u);
        }
        else {
            f[u].push_back(v);
            f[v].push_back(u);
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(!t[i]){
            queue<int> q; q.push(i);
            t[i] = ++ans;
            while(!q.empty()){
                u = q.front(); q.pop();
                for(int j = 0; j < f[u].size(); j++)
                    if(!t[f[u][j]]){
                        q.push(f[u][j]);
                        t[f[u][j]] = ans;
                    }
                for(int j = 0; j < e[u].size(); j++){
                    v = e[u][j];
                    for(int k = 0; k < e[v].size(); k++)
                        if(!t[e[v][k]]){
                            q.push(e[v][k]);
                            t[e[v][k]] = ans;
                        }
                }
            }
        }

    printf("%d\n", ans);
    return 0;
}
