//
// Created by Acka on 2017. 8. 12..
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
int N, M, cnt[1000001], sq;
long long cur, ans[100000], a[100000];

void add(int i){
    cur += ((cnt[a[i]] + 1) * (cnt[a[i]] + 1) - cnt[a[i]] * cnt[a[i]]) * a[i];
    cnt[a[i]]++;
}

void remove(int i){
    cur -= (cnt[a[i]] * cnt[a[i]] - (cnt[a[i]] - 1) * (cnt[a[i]] - 1)) * a[i];
    cnt[a[i]]--;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    sq = sqrt(N);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].l--; q[i].r--;
        q[i].qidx = i;
        q[i].bidx = q[i].l / sq;
    }

    sort(q, q + M);

    add(0);
    int l = 0, r = 0;;
    for(int i = 0; i < M; i++){
        for(int j = l; j < q[i].l; j++) remove(j);
        for(int j = q[i].l; j < l; j++) add(j);
        for(int j = r + 1; j <= q[i].r; j++) add(j);
        for(int j = q[i].r + 1; j <= r; j++) remove(j);
        ans[q[i].qidx] = cur;
        l = q[i].l, r = q[i].r;
    }

    for(int i = 0; i < M; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
