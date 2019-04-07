//
// Created by Acka on 2017. 4. 13..
//

#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

int want[100001], chk[100001], ans;

int dfs(int cur){
    chk[cur] = 1;

    if(chk[want[cur]] == 1){
        chk[want[cur]] = -1;
        return 1;
    }

    int cnt = dfs(want[cur]);
    if(chk[cur] == -1) return cnt;
    else return cnt + 1;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);
        for(int i = 1; i <= N; i++)
            scanf("%d", &want[i]);

        memset(chk, 0, (N + 1) * sizeof(chk[0]));

        int ans = N;
        for(int i = 1; i <= N; i++)
            if(!chk[i]) ans -= dfs(i);

        printf("%d\n", ans);
    }
    return 0;
}
