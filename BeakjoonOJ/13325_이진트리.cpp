//
// Created by Acka on 2017. 1. 19..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int K, B, edge[1 << 21], maxd[1 << 21], ans;

int get_maxd(int cur, int sum){
    if(B <= cur) return maxd[cur] = sum;
    return maxd[cur] = max(get_maxd(cur * 2, sum + edge[cur * 2]),
                           get_maxd(cur * 2 + 1, sum + edge[cur * 2 + 1]));
}

void inc_cost(int cur, int rem){
    if(B <= cur) return ;
    int d1 = rem - maxd[cur * 2];
    inc_cost(cur * 2, rem - d1);
    int d2 = rem - maxd[cur * 2 + 1];
    inc_cost(cur * 2 + 1, rem - d2);
    ans += d1 + d2;
}

int main()
{
    scanf("%d", &K);
    for(int i = 2, all = (1 << (K + 1)); i < all; i++) {
        scanf("%d", &edge[i]);
        ans += edge[i];
    }

    B = 1 << K;
    inc_cost(1, get_maxd(1, 0));

    printf("%d\n", ans);
    return 0;
}

