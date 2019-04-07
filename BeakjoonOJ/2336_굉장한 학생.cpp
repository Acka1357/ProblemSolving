//
// Created by Acka on 9/24/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Score{
    int x, y, z;
    bool operator <(const Score &A)const{
        return x < A.x;
    }
};

int tree[(1 << 20) + 1], nearn = 1;
Score scr[500000];

void change_val(int idx, int val){
    tree[idx + nearn] = val;
    for(int i = (idx + nearn) >> 1; 0 < i; i >>= 1)
        tree[i] = min(tree[i << 1], tree[(i << 1) + 1]);
}

int query_min(int ql, int qr, int l = 0, int r = nearn - 1, int idx = 1){
    if(ql <= l && r <= qr) return tree[idx];
    int half = (l + r) / 2, min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
    if(ql <= half) min1 = query_min(ql, qr, l, half, idx << 1);
    if(half < qr) min2 = query_min(ql, qr, half + 1, r, (idx << 1) + 1);
    return min(min1, min2);
}

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        scr[x - 1].x = i;
    }
    for(int i = 0, y; i < N; i++){
        scanf("%d", &y);
        scr[y - 1].y = i;
    }
    for(int i = 0, z; i < N; i++){
        scanf("%d", &z);
        scr[z - 1].z = i;
    }

    while(nearn < N) nearn <<= 1;
    memset(tree, 0x3f, (nearn << 1) * sizeof(tree[0]));

    sort(scr, scr + N);

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int minz = query_min(0, scr[i].y);
        if(scr[i].z < minz) cnt++;
        change_val(scr[i].y, scr[i].z);
    }

    printf("%d\n", cnt);
    return 0;
}

