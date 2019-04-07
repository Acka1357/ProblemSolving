//
// Created by Acka on 2017. 12. 16..
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#include <memory.h>
using namespace std;

int t[200000];
bool chk[200000];

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    if(K == 1) return 0 & printf("%d\n", N);

    for(int i = 0; i < N; i++)
        scanf("%d", &t[i]);

    sort(t, t + N);

    int ans = 0, li = 0, cnt = 1;
    for(int i = 1; i < N; i++){
        while(t[i] - t[li] >= M || chk[li]){
            if(!chk[li]) cnt--;
            li++;
        }
        cnt++;
        if(cnt >= K){
            cnt--;
            ans++;
            chk[i] = true;
        }
    }

    printf("%d\n", ans);
    return 0;
}

