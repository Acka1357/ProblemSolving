//
// Created by Acka on 2017. 11. 17..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Seg{
    int l, r, len;
    Seg(){} Seg(int l, int r):l(l), r(r), len(r - l){};
    bool operator < (const Seg &o)const{
        return l == o.l ? len > o.len : l < o.l;
    }
};

Seg seg[2000];

int main()
{
    int N, X, Y; scanf("%d %d %d", &N, &X, &Y);

    int base = 2 * (X + Y), x, y; char d;
    for(int i = 0; i < N; i++){
        scanf("%d %d %c", &x, &y, &d);
        if(d == 'W'){
            if(x + y > Y)seg[i] = Seg(base - (x + y - Y), base + Y + x - y);
            else seg[i] = Seg(Y - (x + y), Y + x - y);
        }
        else if(d == 'S') seg[i] = Seg(Y + x - y, Y + x + y);
        else if(d == 'E') seg[i] = Seg(Y + x + y, 2 * X + Y - x + y);
        else{
            if(x + y > Y) seg[i] = Seg(2 * X + Y - x + y, base - (x + y - Y));
            else seg[i] = Seg(2 * X + Y - x + y, base + Y - (x + y));
        }
        seg[N + i] = Seg(base + seg[i].l, base + seg[i].r);
    }

    sort(seg, seg + 2 * N);

    int ans = N;
    for(int s = 0; s < N; s++){
        int cnt = 1, r = seg[s].r;
        for(int i = 1; i < N; i++){
            if(r < seg[s + i].l){
                cnt++;
                r = seg[s + i].r;
            }
            else r = min(r, seg[s + i].r);
        }
        ans = min(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}
