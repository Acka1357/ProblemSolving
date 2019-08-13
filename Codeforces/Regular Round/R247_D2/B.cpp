//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>

int g[10][10], ans, order[5];

void dfs(int idx){
    if(idx == 5){
        int sum = 0;
        for(int i = 0; i < 5; i++)
            for(int j = i; j < 5; j += 2)
                if(j + 1 < 5)
                    sum += g[order[j]][order[j + 1]] + g[order[j + 1]][order[j]];
        if(sum > ans) ans = sum;
    }

    for(int i = 0; i < 5; i++){
        bool psb = true;
        for(int j = 0; j < idx; j++)
            if(order[j] == i) psb = false;
        if(psb){
            order[idx] = i;
            dfs(idx + 1);
        }
    }
}

int main()
{
    for(int i= 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &g[i][j]);

    dfs(0);

    printf("%d\n", ans);
    return 0;
}
