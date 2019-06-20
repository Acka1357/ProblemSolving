//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Cand{
    int idx, sum, cnt[4];
    bool operator < (const Cand &A)const{
        if(sum != A.sum) return sum > A.sum;
        if(cnt[3] != A.cnt[3]) return cnt[3] > A.cnt[3];
        return cnt[2] > A.cnt[2];
    }
};

Cand cand[3];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, x; i < N; i++)
        for(int j = 0; j < 3; j++){
            scanf("%d", &x);
            cand[j].sum += x;
            cand[j].cnt[x]++;
        }

    for(int i = 0; i < 3; i++)
        cand[i].idx = i + 1;

    sort(cand, cand + 3);

    printf("%d %d\n", cand[0] < cand[1] ? cand[0].idx : 0, cand[0].sum);
    return 0;
}
