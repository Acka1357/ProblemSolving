//
// Created by Acka on 2017. 1. 9..
//

#include <stdio.h>

long long int tree[1 << 21], nn;

long long int get_sum(int ql, int qr, int l = 1, int r = nn, int idx = 1){
    if(ql <= l && r <= qr) return tree[idx];
    long long int half = (l + r) / 2, sum = 0;
    if(ql <= half) sum += get_sum(ql, qr, l, half, idx << 1);
    if(half < qr) sum += get_sum(ql, qr, half + 1, r, (idx << 1) + 1);
    return sum;
}

void change_value(int idx, int val){
    tree[idx = (idx + nn - 1)] = val;
    for(idx >>= 1; 0 < idx; idx >>= 1)
        tree[idx] = tree[idx << 1] + tree[(idx << 1) + 1];
}

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    for(nn = 1; nn < N; nn <<= 1);

    for(long long i = 1, x; i <= N; i++){
        scanf("%lld", &x);
        change_value(i, x);
    }

    for(long long Q = M + K, a, b, c; Q--;){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a == 1) change_value(b,  c);
        else printf("%lld\n", get_sum(b, c));
    }

    return 0;
}
