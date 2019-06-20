//
// Created by Acka on 7/31/16.
//

#include <stdio.h>

int p[1001], e[1001];

int find(int x){
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void link(int x, int y){
    p[find(x)] = find(y);
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        p[i] = i;

    char c;
    for(int i = 0, u, v, fu, fv; i < M; i++){
        scanf(" %c %d %d", &c, &u, &v);

        fu = find(u); fv = find(v);
        if(c == 'E'){
            if(e[u]) link(fv, e[u]);
            if(e[v]) link(fu, e[v]);
            e[v] = fu; e[u] = fv;
        }
        else if(fu != fv) link(fu, fv);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(p[i] == i) ans++;

    printf("%d\n", ans);
    return 0;
}

