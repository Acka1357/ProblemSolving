//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

int N, par[200001], p[200001];

int find(int x){
    return x == par[x] ? x : (par[x] = find(p[x]));
}

void link(int x, int y){
    par[find(x)] = find(y);
}

int main()
{
    scanf("%d", &N);

    int root = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &p[i]);
        if(p[i] == i && !root) root = i;
    }

    for(int i = 1; i <= N; i++)
        par[i] = i;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(i == root) continue;
        if(find(p[i]) == i){
            if(!root){ root = i; }
            ans++;
            p[i] = root;
        }
        link(i, p[i]);
    }

    printf("%d\n", ans);
    for(int i = 1; i <= N; i++)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}
