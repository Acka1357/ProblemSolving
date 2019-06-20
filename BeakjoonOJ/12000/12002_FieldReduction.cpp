//
// Created by Acka on 2016. 12. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Crd{
    int x, y, idx;
    Crd(){} Crd(int x, int y, int i):x(x), y(y), idx(i){}
};

bool cmp1(const Crd& A, const Crd& B){
    return A.x < B.x;
}
bool cmp2(const Crd& A, const Crd& B){
    return A.y < B.y;
}

int N, exidx[3];
Crd xa[50000], ya[50000];
bool ex[50000];

void set_ex(int lcnt, int rcnt, int bcnt, int tcnt){
    for(int i = 0; i < 3; i++)
        ex[exidx[i]] = false;

    int cnt = 0;
    for(int i = 0; lcnt; i++) {
        ex[exidx[cnt++] = xa[i].idx] = true;
        lcnt--;
    }
    for(int i = N - 1; rcnt; i--){
        ex[exidx[cnt++] = xa[i].idx] = true;
        rcnt--;
    }
    for(int i = 0; bcnt; i++)
        if (!ex[ya[i].idx]) {
            ex[exidx[cnt++] = ya[i].idx] = true;
            bcnt--;
        }
    for(int i = N - 1; tcnt; i--)
        if(!ex[ya[i].idx]){
            ex[exidx[cnt++] = ya[i].idx] = true;
            tcnt--;
        }
}

long long int get_area(){
    int l = 40001, r = 0, b = 40001, t = 0;
    for(int i = 0; i < N; i++)
        if(!ex[xa[i].idx]) l = min(l, xa[i].x), r = max(r, xa[i].x), b = min(b, xa[i].y), t = max(t, xa[i].y);
    return (long long)(r - l) * (t - b);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0, x, y; i < N; i++){
        scanf("%d %d", &x, &y);
        xa[i] = ya[i] = Crd(x, y ,i);
    }

    sort(xa, xa + N, cmp1);
    sort(ya, ya + N, cmp2);

    long long int ans = 40000ll * 40000;
    for(int i = 0; i <= 3; i++)
        for(int j = i; j <= 3; j++)
            for(int k = j; k <= 3; k++) {
                set_ex(i, j - i, k - j, 3 - k);
                ans = min(ans, get_area());
            }

    printf("%lld\n", ans);
    return 0;
}

