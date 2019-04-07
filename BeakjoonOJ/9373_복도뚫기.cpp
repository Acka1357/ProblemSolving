//
// Created by Acka on 2017. 11. 18..
//

#include <stdio.h>
#include <math.h>
#include <memory.h>

#define sq(x)   ((x) * (x))

struct Circle{
    long long x, y, r;
};

int W, N;
Circle one[1002];
double d[1002][1002], dia;
bool chk[1002];

bool impsb(int cur){
    chk[cur] = true;
    if(d[cur][N + 1] <= dia) return true;
    for(int i = 1; i <= N; i++)
        if(!chk[i] && d[cur][i] < dia){
            if(impsb(i)) return true;
        }
    return false;
}

int main()
{   int T = 0;
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%d %d", &W, &N);
        for(int i = 1; i <= N; i++)
            scanf("%lld %lld %lld", &one[i].x, &one[i].y, &one[i].r);

        d[0][N + 1] = d[N + 1][0] = W;
        for(int i = 1; i <= N; i++){
            d[0][i] = d[i][0] = one[i].x - one[i].r;
            d[N + 1][i] = d[i][N + 1] = W - (one[i].x + one[i].r);
            for(int j = i + 1; j <= N; j++)
                d[i][j] = d[j][i] = sqrt(sq(one[i].x - one[j].x) + sq(one[i].y - one[j].y)) - one[i].r - one[j].r;
        }

        double l = 0, r = W, ans = 0;
        while(r - l > 1e-8){
            dia = (l + r) / 2;
            memset(chk, 0, sizeof(chk));
            if(impsb(0)) r = dia;
            else ans = l = dia;
        }
        printf("%.6lf\n", ans / 2);
    }
    return 0;
}

