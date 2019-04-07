//
// Created by Acka on 2017. 9. 21..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define SQ(x)   ((x) * (x))

const int INF = 0x7fffffff;

struct Crd{
    int x, y;
    bool operator <(const Crd &o)const{
        return x == o.x ? y < o.y : x < o.x;
    }
};

int dist_sq(Crd &A, Crd &B){
    return SQ(A.x - B.x) + SQ(A.y - B.y);
}

Crd crd[100000];

bool ycmp(int a, int b){
    return crd[a].y == crd[b].y ? crd[a].x < crd[b].x : crd[a].y < crd[b].y;
}

int yl[19][100000], yr[19][100000], temp[100000];

int find_mind(int d, int m, int l, int r, int* left, int* right){
    int half = (l + r) / 2, mind = INF, rcnt = 0;
    for(int i = half + 1; i <= r; i++)
        if(SQ(crd[right[i]].x - m) <= d)
            temp[rcnt++] = right[i];
    for(int i = l, j = 0; i <= half; i++){
        if(SQ(m - crd[left[i]].x) > d) continue;
        while(j < rcnt - 1 && crd[left[i]].y >= crd[temp[j + 1]].y && SQ(crd[left[i]].y - crd[temp[j]].y) > d) j++;
        for(int k = min(j + 6, rcnt - 1); k >= j; k--)
            mind = min(mind, SQ(crd[left[i]].x - crd[temp[k]].x) + SQ(crd[left[i]].y - crd[temp[k]].y));
    }
    return mind;
}

int closest(int l, int r, int depth, int *yord){
    if(r - l < 3){
        int ret = INF;
        for(int i = l; i < r; i++)
            for(int j = i + 1; j <= r; j++)
                ret = min(ret, dist_sq(crd[i], crd[j]));
        for(int i = l; i <= r; i++)
            yord[i] = i;
        sort(yord + l, yord + r + 1, ycmp);
        return ret;
    }

    int idx = l, half = (l + r) / 2, il = l, ir = half + 1, nd = depth + 1;
    int d = min(closest(l, half, nd, yl[nd]), closest(half + 1, r, nd, yr[nd]));
    while(il <= half && ir <= r){
        if(ycmp(yl[nd][il], yr[nd][ir])) yord[idx++] = yl[nd][il++];
        else yord[idx++] = yr[nd][ir++];
    }
    while(il <= half) yord[idx++] = yl[nd][il++];
    while(ir <= r) yord[idx++] = yr[nd][ir++];

    return min(d, find_mind(d, crd[half].x, l, r, yl[nd], yr[nd]));
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &crd[i].x, &crd[i].y);
    sort(crd, crd + N);
    printf("%d\n", closest(0, N - 1, 0, yl[0]));
    return 0;
}
