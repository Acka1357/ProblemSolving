//
// Created by Acka on 2017. 1. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Num{
    int x, oi;
    bool operator <(const Num &A)const{
        return x == A.x ? oi < A.oi : x < A.x;
    }
};

Num n[500000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &n[i].x);
        n[i].oi = i;
    }

    sort(n, n + N);

    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, n[i].oi - i);

    printf("%d\n", ans);
    return 0;
}
