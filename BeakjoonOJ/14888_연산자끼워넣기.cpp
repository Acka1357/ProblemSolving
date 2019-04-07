//
// Created by Acka on 2017. 10. 31..
//

#include <stdio.h>

int min = (1 << 30), max = -(1 << 30);
int N, add, sub, mul, div, n[11];

void dfs(int idx, int cur){
    if(idx == N){
        if(cur < min) min = cur;
        if(cur > max) max = cur;
        return ;
    }

    if(add){ add--; dfs(idx + 1, cur + n[idx]); add++; }
    if(sub){ sub--; dfs(idx + 1, cur - n[idx]); sub++; }
    if(mul){ mul--; dfs(idx + 1, cur * n[idx]); mul++; }
    if(div){ div--; dfs(idx + 1, cur / n[idx]); div++; }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);
    scanf("%d %d %d %d", &add, &sub, &mul, &div);

    dfs(1, n[0]);
    printf("%d\n%d\n", max, min);
    return 0;
}
