//
// Created by Acka on 2017. 9. 4..
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Info{
    int n[3], sum, idx;
    bool operator <(const Info &A)const{
        return sum == A.sum ?(n[0] == A.n[0] ?(n[1] == A.n[1] ? (n[2] == A.n[2] ? idx < A.idx : n[2] >A.n[2]) : n[1] >A.n[1]) : n[0]> A.n[0]) : sum > A.sum;
    }
};

Info info[301];
int infoi[1000001];

int main()
{
    int N, d, x, idx;
    while(scanf("%d", &N) == 1){
        if(!N) break;
        memset(info, 0, sizeof(info));
        memset(infoi, 0, sizeof(infoi));
        for(int i = idx = 0; i < N; i++){
            scanf("%d", &d);
            for(int j = 0; j <d; j++){
                scanf("%d", &x);
                if(infoi[x] == 0){
                    infoi[x] = ++idx;
                    info[idx].idx = x;
                }
                info[infoi[x]].n[j]++;
                info[infoi[x]].sum += 3 - j;
            }
        }

        sort(info +1, info + 1+ idx);
        printf("%d ", info[1].idx);
        for(int i = 2; i <= idx; i++){
            bool same = (info[i].sum == info[1].sum);
            for(int j = 0; j <3; j++)
                if(info[i].n[j] != info[1].n[j])
                    same = false;
            if(same) printf("%d ", info[i].idx);
            else break;
        }
        printf("\n");
    }
    return 0;
}
