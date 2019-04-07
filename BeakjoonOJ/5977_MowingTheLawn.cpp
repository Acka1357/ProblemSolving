//
// Created by Acka on 2016. 12. 24..
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, K, nn;
long long int tree[2 << 18], d[100003], v[100003], acc[100004];

void set_value(int idx, long long int val){
    tree[nn + idx] = val;
    for(int i = (nn + idx) >> 1; 0 < i; i >>= 1)
        tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
}

long long int get_max(int ql, int qr, int l = 0, int r = nn - 1, int idx = 1){
    if(ql <= l && r <= qr) return tree[idx];
    int half = (l + r) / 2;
    long long int max1 = 0x8080808080808080, max2 = 0x8080808080808080;
    if(ql <= half) max1 = get_max(ql, qr, l, half, idx << 1);
    if(half < qr) max2 = get_max(ql, qr, half + 1, r, (idx << 1) + 1);
    return max(max1, max2);
}

int main()
{
    memset(tree, 0x80, sizeof(tree));

    scanf("%d %d", &N, &K);
    for(int i = 2; i < N + 2; i++) {
        scanf("%lld", &v[i]);
        acc[i] = acc[i - 1] + v[i];
    }

    N += 2;
    for(nn = 1; nn < N; nn <<= 1);

    set_value(0, 0);
    long long int ans = 0;
    for(int i = 1; i < N; i++){
        d[i] = get_max(K < i ? i - K - 1 : 0, i) + acc[i];
        set_value(i, d[i] - acc[i + 1]);
        ans = max(ans, d[i]);
    }

    printf("%lld\n", ans);
    return 0;
}



