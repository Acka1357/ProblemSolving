//
// Created by Acka on 2017. 9. 7..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int to[500001];
long long len[500001];
bool chk[500001];

int dfs(int cur, int cnt){
    if(chk[cur]) return len[cur] = cnt;
    chk[cur] = true;
    return len[cur] = dfs(to[cur], cnt + 1);
}

int main()
{
    int N, A, B, C, D; scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
    for(int i = 1; i <= N; i++)
        scanf("%d", &to[i]);

    for(int i = 1; i <= N; i++)
        if(!chk[i]) dfs(i, 0);

    long long lcm = len[C + 1];
    for(int i = C + 2, im = N - D; i <= im; i++)
        lcm = lcm / __gcd(lcm, len[i]) * len[i];

    printf("%lld\n", (B - 1) / lcm - (A < 2 ? 0 : (A - 2) / lcm) + (A == 1 ? 1 : 0));
    return 0;
}
