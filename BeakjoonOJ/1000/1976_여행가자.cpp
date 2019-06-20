//
// Created by Acka on 2017. 11. 7..
//

#include <stdio.h>

int p[201];

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}

void link(int x, int y){
    int px = find(x), py = find(y);
    if(px != py) p[px] = py;
}

int main()
{
    int N, M, x; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) p[i] = i;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(i <= j) scanf("%*d");
            else{
                scanf("%d", &x);
                if(x) link(i, j);
            }
        }

    scanf("%d", &x);
    for(int i = 1, px = find(x); i < M; i++){
        scanf("%d", &x);
        if(find(x) != px) return 0 & printf("NO\n");
    }
    printf("YES\n");
    return 0;
}
