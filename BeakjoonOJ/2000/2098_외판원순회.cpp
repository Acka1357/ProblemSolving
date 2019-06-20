//
// Created by Acka on 2017. 5. 25..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF     0x3f3f3f3f

int minc[16][1 << 16], w[16][16], bit[16] = {1};

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &w[i][j]);

    for(int i = 1; i < N; i++)
        bit[i] = bit[i - 1] << 1;

    memset(minc, 0x3f, sizeof(minc));

    minc[0][bit[0]] = 0;
    int all_visit = (1 << N) - 1;
    for(int visited = 1; visited <= all_visit; visited++)
        for(int cur = 0; cur < N; cur++){
            if(visited & bit[cur] == 0) continue;
            for(int next = 1; next < N; next++){
                if(visited & bit[next] || !w[cur][next]) continue;
                minc[next][visited | bit[next]] = min(
                        minc[next][visited | bit[next]],
                        minc[cur][visited] + w[cur][next]);
            }
        }

    int ans = INF;
    for(int i = 1; i < N; i++)
        if(w[i][0]){
            ans = min(ans, minc[i][all_visit] + w[i][0]);
        }

    printf("%d\n", ans);
    return 0;
}
