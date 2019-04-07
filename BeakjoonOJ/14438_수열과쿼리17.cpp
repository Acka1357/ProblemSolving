//
// Created by Acka on 2017. 5. 25..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF     1000000001

int NN, tree[400001];

int range_min(int ql, int qr, int idx, int l, int r){
    if(ql <= l && r <= qr) return tree[idx];
    if(qr < l || r < ql) return INF;
    return min(range_min(ql, qr, idx * 2, l, (l + r) / 2),
            range_min(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void change_value(int idx, int value){
    tree[NN + idx - 1] = value;
    for(int cur = (NN + idx - 1) / 2; cur > 0; cur /= 2)
        tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
}

int main()
{
    int N; scanf("%d", &N);
    for(NN = 1; NN < N; NN <<= 1);

    for(int i = 1, x; i <= N; i++)
        scanf("%d", &tree[NN + i - 1]);
    for(int i = N + 1; i <= NN; i++)
        tree[NN + i - 1] = INF;

    for(int i = NN - 1; i > 0; i--)
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

    int M, a, b, c; scanf("%d", &M);
    while(M--){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) change_value(b,  c);
        else printf("%lld\n", range_min(b, c, 1, 1, NN));
    }

    return 0;
}
