//
// Created by Acka on 2017. 8. 14..
//

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct Query{
    int l, r, qidx, bidx;
    bool operator <(const Query &A)const{
        return bidx == A.bidx ? r < A.r : bidx < A.bidx;
    }
};

Query q[100000];
int N, M;
int a[100000], cnt[1000001], ans[100000], sq, cur;

void add(int i){
    if(cnt[a[i]]++ == 0) cur++;
}

void remove(int i){
    if(--cnt[a[i]] == 0) cur--;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sq = sqrt(N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].l--; q[i].r--;
        q[i].qidx = i;
        q[i].bidx = q[i].l / sq;
    }

    sort(q, q + M);

    add(0);
    int l = 0, r = 0;
    for(int i = 0; i < M; i++){
        for(int j = l; j < q[i].l; j++) remove(j);
        for(int j = q[i].l; j < l; j++) add(j);
        for(int j = r + 1; j <= q[i].r; j++) add(j);
        for(int j = q[i].r + 1; j <= r; j++) remove(j);
        ans[q[i].qidx] = cur;
        l = q[i].l, r = q[i].r;
    }

    for(int i = 0; i < M; i++)
        printf("%d\n", ans[i]);

    return 0;
}
