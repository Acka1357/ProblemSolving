//
// Created by Acka on 2017. 6. 12..
//

#include <stdio.h>

int N, M, V;
bool adj[1001][1001];
bool chk[1001];

void print_dfs(int cur){
    printf("%d ", cur);
    chk[cur] = true;

    for(int i = 1; i <= N; i++)
        if(adj[cur][i] && !chk[i])
            print_dfs(i);
}

void print_bfs(){
    for(int i = 1; i <= N; i++)
        chk[i] = false;

    int q[1000], head = 0, tail = 0;
    q[tail++] = V;
    chk[V] = true;

    while(head < tail){
        int cur = q[head];
        printf("%d ", cur);

        for(int i = 1; i <= N; i++)
            if(adj[cur][i] && !chk[i]){
                q[tail++] = i;
                chk[i] = true;
            }
        head++;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = true;
    }

    print_dfs(V);
    printf("\n");

    print_bfs();
    printf("\n");

    return 0;
}

