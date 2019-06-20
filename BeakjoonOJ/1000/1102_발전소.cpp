//
// Created by Acka on 2017. 11. 7..
//

#include <stdio.h>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF     0x3f3f3f3f

char s[17];
int c[16][16], d[1 << 16], bit[16], cnt[1 << 16];

int main()
{
    int N, P; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &c[i][j]);
    scanf("%s %d", s, &P);

    for(int i = bit[0] = 1; i < N; i++)
        bit[i] = bit[i - 1] << 1;

    memset(d, 0x3f, sizeof(d));
    int st_b = 0, st_cnt = 0;
    for(int i = 0; s[i]; i++)
        if(s[i] == 'Y') st_b |= bit[i], st_cnt++;
    queue<int> q; q.push(st_b);
    cnt[st_b] = st_cnt;
    d[st_b] = 0;

    int ans = INF;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cnt[cur] >= P){
            ans = min(ans, d[cur]);
            continue;
        }
        for(int i = 0; i < N; i++){
            if(cur & bit[i]) continue;
            int add = INF, next = cur + bit[i];
            for(int j = 0; j < N; j++)
                if(cur & bit[j]) add = min(add, c[j][i]);
            if(d[next] == INF) q.push(next);
            d[next] = min(d[next], d[cur] + add);
            cnt[next] = cnt[cur] + 1;
        }
    }

    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
