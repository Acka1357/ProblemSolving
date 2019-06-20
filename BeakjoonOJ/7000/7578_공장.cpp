//
// Created by Acka on 2017. 5. 25..
//

#include <stdio.h>

int NN, tree[4000001];
int ai[1000001], bi[1000001];

long long range_sum(int ql, int qr, int idx, int l, int r){
    if(ql <= l && r <= qr) return tree[idx];
    if(qr < l || r < ql) return 0;
    return range_sum(ql, qr, idx * 2, l, (l + r) / 2)
           + range_sum(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

void change_value(int idx, int value){
    tree[NN + idx - 1] = value;
    for(int cur = (NN + idx - 1) / 2; cur > 0; cur /= 2)
        tree[cur] = tree[cur * 2] + tree[cur * 2+ 1];
}

int main()
{
    int N, x; scanf("%d", &N);
    for(NN = 1; NN < N; NN <<= 1);

    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        ai[x] = i;
    }

    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        bi[ai[x]] = i;
    }

	long long ans = 0;
	for (int i = 1; i <= N; i++){
        change_value(bi[i], 1);
        if(bi[i] < NN)
            ans += range_sum(bi[i] + 1, NN, 1, 1, NN);
	}

	printf("%lld\n", ans);
	return 0;
}
