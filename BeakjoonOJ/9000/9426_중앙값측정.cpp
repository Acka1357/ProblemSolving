//
// Created by Acka on 2017. 7. 26..
//

#include <stdio.h>

int n[250001], tree[65537];

void add_val(int idx, int value){
    for(; idx <= 65536; idx += (idx & -idx))
        tree[idx] += value;
}

int get_acc(int idx){
    int sum = 0;
    for(; idx > 0; idx -= (idx & -idx))
        sum += tree[idx];
    return sum;
}

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    long long ans = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &n[i]);
        add_val(n[i] + 1, 1);

        if(i < K) continue;
        int l = 1, r = 65536, m, mid;
        while(l <= r){
            m = (l + r) / 2;
            if(get_acc(m) < (K + 1) / 2) l = m + 1;
            else{
                mid = m;
                r = m - 1;
            }
        }
        ans += mid - 1;
        add_val(n[i - K + 1] + 1, -1);
    }

    printf("%lld\n", ans);
    return 0;
}
