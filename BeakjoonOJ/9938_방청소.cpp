//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>

int p[300001], ecnt[300001], ncnt[300001];

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}

int link(int px, int py){
    ecnt[px] += ecnt[py] + 1;
    ncnt[px] += ncnt[py];
    p[py] = px;
}

int main()
{
    int N, L; scanf("%d %d", &N, &L);
    for(int i = 1; i <= L; i++)
        p[i] = i, ncnt[i] = 1;

    int pa, pb, u, v;
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &u, &v);
        pa = find(u);
        pb = find(v);
        if(pa == pb){
            if(ecnt[pa] < ncnt[pa]){
                printf("LADICA\n");
                ecnt[pa]++;
            }
            else printf("SMECE\n");
        }
        else{
            if(ecnt[pa] + ecnt[pb] < ncnt[pa] + ncnt[pb]){
                printf("LADICA\n");
                link(pa, pb);
            }
            else printf("SMECE\n");
        }
    }

    return 0;
}


