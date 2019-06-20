//
// Created by Acka on 7/22/16.
//

#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

struct Cow{
    int c, i;
    bool operator <(const Cow &A)const{
        return c < A.c;
    }
};

int main()
{
    long long int N, K, M; scanf("%lld %lld %lld", &N, &K, &M);

    int org[50000];
    Cow cp[50000], cc[50000];
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &cp[i].c, &cc[i].c);
        cp[i].i = cc[i].i = i;
        org[i] = cp[i].c;
    }

    sort(cc, cc + N);
    sort(cp, cp + N);

    long long int sum = 0, cnt = 0;
    bool chk[50000] = {false,};
    priority_queue<int, vector<int>, greater<int> > q;
    while(K--){
        if(M < sum + cc[cnt].c) break;
        q.push(org[cc[cnt].i] - cc[cnt].c);
        sum += cc[cnt].c;
        chk[cc[cnt++].i] = true;
    }

    int ci = cnt, pi = 0;
    while(cnt < N){
        if(M < sum + cc[ci].c) break;

        while(chk[cc[ci].i]) ci++;
        while(chk[cp[pi].i]) pi++;

        if(cc[ci].c + q.top() < cp[pi].c){
            sum += q.top() + cc[ci].c; q.pop();
            q.push(org[cc[ci].i] - cc[ci].c);
            chk[cc[ci++].i] = true;
        }
        else {
            sum += cp[pi].c;
            chk[cp[pi++].i] = true;
        }

        if(M < sum) break;
        cnt++;
    }

    printf("%lld\n", cnt);
    return 0;
}

