//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>
#include <queue>
using namespace std;

bool chk[200001], chk2[200001];
long long sum[200001], ans;
int in[200001], to[200001], cost[200001];

int dfs(int cur){
    chk[cur] = true;
    int ret = cur;
    if(!chk[to[cur]]){
        ret = dfs(to[cur]);
        if(cost[cur] - sum[cur] < cost[ret] - sum[ret])
            ret = cur;
    }
    return ret;
}

void add_diff(int cur){
    chk2[cur] = true;
    if(sum[cur] < cost[cur]) ans += cost[cur] - sum[cur];
    sum[to[cur]] += cost[cur];
    if(!chk2[to[cur]]) add_diff(to[cur]);
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &to[i], &cost[i]);
        in[to[i]]++;
    }

    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(!in[i]) q.push(i);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        chk[cur] = true;

        if(sum[cur] < cost[cur]) ans += cost[cur] - sum[cur];
        sum[to[cur]] += cost[cur];
        if(!(--in[to[cur]])) q.push(to[cur]);
    }

    for(int i = 1; i <= N; i++){
        if(chk[i]) continue;
        add_diff(dfs(i));
    }

    printf("%lld\n", ans);
    return 0;
}
