//
// Created by Acka on 2017. 8. 1..
//

#include <stdio.h>

int par[100001];
long long dist[100001];

int find(int x){
    if(x == par[x]) return x;
    int p = find(par[x]);
    dist[x] += dist[par[x]];
    return par[x] = p;
}

void link(int x, int y, int w){
    int px = find(x), py = find(y);
    if(px == py) return ;
    par[py] = px;
    dist[py] = dist[x] + w - dist[y];
}

int main()
{
    char cmd;
    int N, M, a, b, w;
    while(scanf("%d %d", &N, &M) == 2){
        if(!N && !M) break;

        for(int i = 1; i <= N; i++)
            par[i] = i, dist[i] = 0;

        while(M--){
            scanf(" %c %d %d", &cmd, &a, &b);
            if(cmd == '!'){
                scanf("%d", &w);
                link(a, b, w);
            }
            else{
                if(find(a) == find(b))
                    printf("%lld\n", dist[b] - dist[a]);
                else printf("UNKNOWN\n");
            }
        }
    }

    return 0;
}
