//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define PNCOUNT 670122
#define MOD     1000000007

struct Pnum{
    long long int x, p;
    bool operator <(const Pnum &A)const{
        return x < A.x;
    }
};

Pnum pnum[PNCOUNT];
bool notP[10000001] = {true, true,};
int pn = 1;
long long int ans[PNCOUNT] = {1,};

void set_prime(){
    long long int j, i;
    for(i = 2; i <= 10000000; i++)
        if(!notP[i]){
            for(j = i * i; j <= 100000000000000; j *= i) {
                pnum[pn].x = j; pnum[pn++].p = i;
                if(100000000000 <= j && 10000 <= i) break;
            }
            for(j = i * i; j <= 10000000; j+= i)
                notP[j] = true;
        }
}

int main()
{
    pnum[0].p = pnum[0].x = 0;

    set_prime();

    sort(pnum, pnum + pn);

    for(int i = 1; i < pn; i++)
        ans[i] = (ans[i - 1] * pnum[i].p) % MOD;

    int tc, st = 0; for(scanf("%d", &tc); st++ < tc;){
        long long int N; scanf("%lld", &N);
        int l = 0, r = pn - 1, m, x;
        while(l <= r){
            m = (l + r) / 2;

            if(N < pnum[m].x)r = m - 1;
            else { x = m; l = m + 1; }
        }
        printf("Case %d: %lld\n", st, ans[x]);
    }
    return 0;
}
