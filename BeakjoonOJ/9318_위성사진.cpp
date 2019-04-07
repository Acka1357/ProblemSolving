//
// Created by Acka on 2017. 7. 14..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Line{
    int x, btm, top, sign;
    Line(){}
    Line(int x, int b, int t, int s):x(x), btm(b), top(t), sign(s){}
    bool operator <(const Line &A)const{
        return x < A.x;
    }
};

Line line[2000];
int NN, tree[1 << 21], nzero[1 << 21];

void add_value(int qb, int qt, int val, int idx = 1, int b = 0, int t = NN - 1){
    if(t < qb || qt < b) return ;
    if(qb <= b && t <= qt) tree[idx] += val;
    else{
        add_value(qb, qt, val, idx * 2, b, (b + t) / 2);
        add_value(qb, qt, val, idx * 2 + 1, (b + t) / 2 + 1, t);
    }

    if(tree[idx]) nzero[idx] = t - b + 1;
    else nzero[idx] = (t == b ? 0 : nzero[idx * 2] + nzero[idx * 2 + 1]);
}

int main()
{
    for(NN = 1; NN <= 1000000; NN *= 2);

    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);
        int x1, x2, y1, y2, lcnt = 0;
        for(int i = 0; i < N; i++){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            line[lcnt++] = Line(x1, y1, y2, 1);
            line[lcnt++] = Line(x2, y1, y2, -1);
        }

        sort(line, line + lcnt);

        long long ans = 0;
        long long pastx = line[0].x;
        add_value(line[0].btm, line[0].top - 1, line[0].sign);
        for(int i = 1; i < lcnt; i++){
            if(line[i].x != pastx){
                ans += (line[i].x - pastx) * nzero[1];
                pastx = line[i].x;
            }
            add_value(line[i].btm, line[i].top - 1, line[i].sign);
        }

        printf("%lld\n", ans);
    }
    return 0;
}

