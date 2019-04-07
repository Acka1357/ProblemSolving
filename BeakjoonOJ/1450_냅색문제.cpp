//
// Created by Acka on 2017. 11. 3..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, C, w[30], wsum[1 << 15], wcnt, ans;

int find_idx(int cval){
    int l = 0, r = wcnt - 1, m, ret;
    while(l <= r){
        m = (l + r) / 2;
        if(wsum[m] > cval) r = m - 1;
        else ret = m, l = m + 1;
    }
    return ret;
}

void dfs(int idx, int end, long long sum){
    if(idx == end){
        if(end != N) wsum[wcnt++] = sum;
        else ans += find_idx(C - sum) + 1;
        return ;
    }
    dfs(idx + 1, end, sum);
    if(sum + w[idx] <= C)
        dfs(idx + 1, end, sum + w[idx]);
}

int main()
{
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++)
        scanf("%d", &w[i]);

    dfs(0, N / 2, 0);
    sort(wsum, wsum + wcnt);
    dfs(N / 2, N, 0);

    printf("%d\n", ans);
    return 0;
}
