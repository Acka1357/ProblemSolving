//
// Created by Acka on 2017. 1. 13..
//

#include <stdio.h>
#include <unordered_map>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF     0x3f3f3f3f

struct Ship{
    int x1, y1, x2, y2, w;
    Ship(){}
    Ship(int x1, int y1, int x2, int y2, int w):x1(min(x1, x2)), y1(min(y1, y2)), x2(max(x1, x2)), y2(max(y1, y2)), w(w){}
};

Ship ship[100000];
int laser[100000][2], xtree[1 << 20], ytree[1 << 20], xs[300000], ys[300000], ans[100000];

int get_min(int* tree, int &N, int &ql, int &qr){
    int minx = tree[N + ql], l = N + ql, r = N + qr;
    while(l <= r){
        if(l & 1) minx = min(minx, tree[l]);
        if(!(r & 1)) minx = min(minx, tree[r]);
        l = (l + 1) >> 1; r = (r - 1) >> 1;
    }
    return minx;
}

void set_value(int* tree, int &N, int &idx, int &val){
    if(tree[N + idx] < INF) return;
    tree[N + idx] = val;
    for(int i = (N + idx) >> 1; 0 < i; i >>= 1)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int K, L; scanf("%*d %d %d", &K, &L);

        int xcnt = 0, ycnt = 0;
        for(int i = 0, x1, y1, x2, y2, w; i < K; i++){
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &w);
            ship[i] = Ship(x1, y1, x2, y2, w);
            xs[xcnt++] = x1; xs[xcnt++] = x2;
            ys[ycnt++] = y1; ys[ycnt++] = y2;
        }

        for(int i = 0; i < L; i++){
            scanf("%d %d", &laser[i][0], &laser[i][1]);
            if(laser[i][1]) xs[xcnt++] = laser[i][0];
            else ys[ycnt++] = laser[i][0];
        }

        sort(xs, xs + xcnt); sort(ys, ys + ycnt);

        int X = 0, Y = 0;
        unordered_map<int, int> xidx, yidx;
        xidx[xs[0]] = X++; yidx[ys[0]] = Y++;
        for(int i = 1; i < xcnt; i++)
            if(xs[i] != xs[i - 1]) xidx[xs[i]] = X++;
        for(int i = 1; i < ycnt; i++)
            if(ys[i] != ys[i - 1]) yidx[ys[i]] = Y++;

        int XB = 1, YB = 1;
        while(XB < X) XB <<= 1;
        while(YB < Y) YB <<= 1;

        memset(xtree, 0x3f, 2 * XB * sizeof(xtree[0]));
        memset(ytree, 0x3f, 2 * YB * sizeof(ytree[0]));

        for(int i = 0; i < L; i++){
            if(laser[i][1]) set_value(xtree, XB, xidx[laser[i][0]], i);
            else set_value(ytree, YB, yidx[laser[i][0]], i);
        }

        memset(ans, 0, L * sizeof(ans[0]));
        for(int i = 0, hit; i < K; i++) {
            hit = min(get_min(xtree, XB, ship[i].x1, ship[i].x2),
                      get_min(ytree, YB, ship[i].y1, ship[i].y2));
            if(hit < INF) ans[hit] = max(ans[hit], ship[i].w);
        }

        for(int i = 0; i < L; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
