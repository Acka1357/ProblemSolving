//
// Created by Acka on 2017. 9. 14..
//

#include <stdio.h>

int tree[1 << 19], NN;

int range_sum(int ql, int qr, int idx = 1, int l = 1, int r = NN){
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return tree[idx];
    return range_sum(ql, qr, idx * 2, l, (l + r) / 2)
            + range_sum(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

void remove(int idx){
    tree[NN + idx - 1] = 1;
    for(idx = (NN + idx - 1) / 2; idx > 0; idx /= 2)
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(NN = 1; NN < N; NN <<= 1);

    int cmd, x, add = -1;
    while(M--){
        scanf("%d %d", &cmd, &x);
        if(cmd == 1){
            remove(x);
            if(add < 0) add = (x < N / 2 ? 1 : 0);
        }
        else{
            int l = 1, r = N, m, ans = 0, cur;
            while(l <= r){
                m = (l + r) / 2;
                if(m <= (N + (add < 0 ? 0 : add)) / 2)
                    cur = m - range_sum(1, m - 1);
                else cur = m + range_sum(m + 1, N);
                if(cur < x) l = m + 1;
                else if(cur > x) r = m - 1;
                else if(tree[NN + m - 1]){
                    if(m <= (N + (add < 0 ? 0 : add)) / 2) l = m + 1;
                    else r = m - 1;
                }
                else{
                    ans = m;
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
