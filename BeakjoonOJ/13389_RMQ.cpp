//
// Created by Acka on 10/15/16.
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Query{
    int l, r, maxx;
    bool operator <(const Query &A)const{
        return maxx < A.maxx;
    }
};

bool used[102];
int crd[102], chk[102];
Query qer[51];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &qer[i].l, &qer[i].r, &qer[i].maxx);
        crd[i * 2] = qer[i].l;
        crd[i * 2 + 1] = qer[i].r + 1;
    }

    crd[2 * M] = 1; crd[2 * M + 1] = N + 1;
    sort(crd, crd + 2 * M + 2);

    int crds = 1;
    for(int i = 1; i < 2 * M + 2; i++)
        if(crd[i] != crd[i - 1]) crd[crds++] = crd[i];

    bool psb = true;
    sort(qer, qer + M);
    for(int i = 0, dup = 0, acc = 0; i < M && psb; i++){
        for(int j = 1; j < crds; j++)
            if(qer[i].l <= crd[j - 1] && crd[j] - 1 <= qer[i].r) chk[j]++;
        dup++;

        if(qer[i].maxx != qer[i + 1].maxx || i == M - 1) {
            int sum = 0;
            bool find = false;
            for(int j = 1; j < crds; j++) {
                if (chk[j] == dup && !used[j]) find = true;
                if (chk[j] && !used[j]){
                    used[j] = true;
                    sum += crd[j] - crd[j - 1];
                }
            }

            if(qer[i].maxx < (acc = (acc + sum)) || !find) psb = false;
            memset(chk, 0, sizeof(chk));
            dup = 0;
        }
    }

    printf("%d\n", psb ? 1 : 0);
    return 0;
}
