//
// Created by Acka on 2017. 5. 1..
//

#include <stdio.h>

struct Node{
    int org, hold;
};

int NN;
Node tree[1 << 20];

int xor_value(int ql, int qr, int val, int idx = 1, int l = 0, int r = NN - 1){
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr){
        tree[idx].hold ^= val;
        return (l == r) ? val : 0;
    }

    int lx = xor_value(ql, qr, val, idx * 2, l, (l + r) / 2);
    int rx = xor_value(ql, qr, val, idx * 2 + 1, (l + r) / 2 + 1, r);
    tree[idx].org ^= lx ^ rx;
    return lx ^ rx;
}

int range_xor(int ql, int qr, int idx = 1, int l = 0, int r = NN - 1, int hold = 0){
    if(r < ql || qr < l) return 0;
    hold ^= tree[idx].hold;
    if(ql <= l && r <= qr) return tree[idx].org ^ ((l == r) ? hold : 0);
    return range_xor(ql, qr, idx * 2, l, (l + r) / 2, hold)
            ^ range_xor(ql ,qr, idx * 2 + 1, (l + r)/ 2 + 1, r, hold);
}

int main()
{
    int N; scanf("%d", &N);
    for(NN = 1; NN < N; NN <<= 1);
    for(int i = 0; i < N; i++)
        scanf("%d", &tree[NN + i].org);
    for(int i = NN - 1; i > 0; i--)
        tree[i].org = tree[i * 2].org ^ tree[i * 2 + 1].org;

    int M, t, a, b, c; scanf("%d", &M);
    while(M--){
        scanf("%d %d %d", &t, &a, &b);
        if(a > b){ a ^= b; b ^= a; a ^= b;}
        if(t == 1){
            scanf("%d", &c);
            xor_value(a, b, c);
        }
        else printf("%d\n", range_xor(a, b));
    }
    return 0;
}

