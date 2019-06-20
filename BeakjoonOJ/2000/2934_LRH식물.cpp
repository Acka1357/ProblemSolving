//
// Created by Acka on 2017. 8. 2..
//

#include <stdio.h>

int tree[100001], dup[100001];

void add_val(int idx, int val){
    for(; idx <= 100000; idx += (idx & -idx))
        tree[idx] += val;
}

int get_acc(int idx){
    int sum = 0;
    for(; idx > 0; idx -= (idx & -idx))
        sum += tree[idx];
    return sum;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, l, r; i < N; i++){
        scanf("%d %d", &l, &r);

        int cntl = get_acc(l) - dup[l], cntr = get_acc(r) - dup[r];
        printf("%d\n", cntl + cntr);
        dup[l] += cntl; dup[r] += cntr;
        add_val(l + 1, 1); add_val(r, -1);
    }

    return 0;
}

