//
// Created by Acka on 2017. 2. 5..
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

struct Info{
    int cur, visited;
    Info(){} Info(int c, int v):cur(c), visited(v){}
};

int d[16][1 << 16];
bool chk[16][1 << 16];

int main()
{
    int N; scanf("%d", &N);

    int w[16][16];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &w[i][j]);

    memset(d, 0x3f, sizeof(d));
    queue<Info> q;
    q.push(Info(0, 1));
    d[0][1] = 0;
    while(!q.empty()){
        int cur = q.front().cur, visited = q.front().visited; q.pop();

        for(int i = 1, b = 2; i < N; i++, b <<= 1)
            if(!(visited & b) && w[cur][i]){
                int nv = visited + b;
                d[i][nv] = min(d[i][nv], d[cur][visited] + w[cur][i]);
                if(!chk[i][nv]) {
                    q.push(Info(i, nv));
                    chk[i][nv] = true;
                }
            }
    }

    int ans = 0x3f3f3f3f, all = (1 << N) - 1;
    for(int i = 1; i < N; i++)
        if(w[i][0]) ans = min(ans, d[i][all] + w[i][0]);

    printf("%d\n", ans);
    return 0;
}
