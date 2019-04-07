//
// Created by Acka on 2017. 4. 14..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Query{
    int l, r, k, idx;
    bool operator < (const Query &A)const{
        return A.k < k;
    }
};

struct Elem{
    int x, idx;
    bool operator <(const Elem &A)const{
        return A.x < x;
    }
};

int tree[1 << 18], NN;

int get_sum(int ql, int qr, int idx, int l, int r){
    if(ql <= l && r <= qr) return tree[idx];
    int half = (l + r) / 2, sum = 0;
    if(ql <= half) sum += get_sum(ql, qr, idx * 2, l, half);
    if(half < qr) sum += get_sum(ql, qr, idx * 2+ 1, half + 1, r);
    return sum;
}

void set_value(int idx, int value){
    idx += NN;
    tree[idx] = value;
    for(idx /= 2; 0 < idx; idx /= 2)
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

Query q[100000];
Elem a[100000];
int ans[100000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i].x);
        a[i].idx = i;
    }

    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
        q[i].idx = i;
    }

    sort(a, a + N);
    sort(q, q + Q);

    for(NN = 1; NN < N; NN *= 2);

    for(int ai = 0, qi = 0; qi < Q; qi++){
        if(ai < N){
            while(q[qi].k < a[ai].x){
                set_value(a[ai].idx, 1);
                if(++ai == N) break;
            }
        }
        ans[q[qi].idx] = get_sum(q[qi].l - 1, q[qi].r - 1, 1, 0, NN - 1);
    }

    for(int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);

    return 0;
}
