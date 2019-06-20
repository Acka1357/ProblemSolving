//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Block{
    int idx, a, h, w;
    bool operator <(const Block &A)const{
        return a > A.a;
    }
};

Block bk[100];
int d[100], past[100], cnt[100];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &bk[i].a, &bk[i].h, &bk[i].w);
        bk[i].idx = i + 1;
    }

    sort(bk, bk + N);

    int ans = 0, last = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++)
            if(bk[i].w < bk[j].w && d[i] < d[j]){
                d[i] = d[j];
                past[i] = j;
                cnt[i] = cnt[j];
            }
        d[i] += bk[i].h;
        cnt[i]++;

        if(ans < d[i]){
            ans = d[i];
            last = i;
        }
    }

    printf("%d\n", cnt[last]);
    for(int i = cnt[last]; i > 0; i--, last = past[last])
        printf("%d\n", bk[last].idx);

    return 0;
}
