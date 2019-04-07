//
// Created by Acka on 2017. 11. 7..
//

#include <stdio.h>

int right[100001];

int most_right(int x){
    return right[x] == x ? x : right[x] = most_right(right[x]);
}

void link(int l, int r){
    right[r] = right[most_right(l)];
}

int main()
{
    int G, P; scanf("%d %d", &G, &P);
    for(int i = 1; i <= G; i++)
        right[i] = i;

    int ans = 0, g, idx;
    for(int i = 0; i < P; i++, ans++){
        scanf("%d", &g);
        idx = most_right(g);
        if(!idx) break;
        link(idx - 1, idx);
    }

    printf("%d\n", ans);
    return 0;
}
