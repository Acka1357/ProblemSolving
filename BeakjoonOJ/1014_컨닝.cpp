//
// Created by Acka on 2017. 10. 31..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int count_bit(unsigned int u) {
    unsigned int cnt = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((cnt + (cnt >> 3)) & 030707070707) % 63;
}

char s[11];
int map[11], d[11][1 << 10], mask[1 << 10], mcnt, add[1 << 10], p[11] = {1,};

int main()
{
    for(int i = 1; i <= 10; i++)
        p[i] = p[i - 1] << 1;

    int tc; for(scanf("%d", &tc); tc--;){
        memset(d, 0, sizeof(d));

        int N, M; scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++){
            scanf("%s", s);
            map[i] = 0;
            for(int j = 0; j < M; j++){
                map[i] <<= 1;
                if(s[j] == 'x') map[i]++;
            }
        }

        mcnt = 0;
        for(int i = 0; i < p[M]; i++){
            bool chk = true;
            for(int j = 1; j < M && chk; j++)
                if((i & p[j]) && (i & p[j - 1])) chk = false;
            if(chk){
                mask[mcnt] = i, add[mcnt] = count_bit(i);
                mcnt++;
            }
        }

        for(int i = 1; i <= N; i++)
            for(int past = 0; past < mcnt; past++){
                if(map[i - 1] & mask[past]) continue;
                for(int cur = 0; cur < mcnt; cur++){
                    if(map[i] & mask[cur]) continue;
                    if(((mask[past] << 1) & mask[cur]) || ((mask[past] >> 1) & mask[cur])) continue;
                    d[i][cur] = max(d[i][cur], d[i - 1][past] + add[cur]);
                }
            }

        int ans = 0;
        for(int i = 0; i < mcnt; i++)
            ans = max(ans, d[N][i]);
        printf("%d\n", ans);
    }
    return 0;
}
