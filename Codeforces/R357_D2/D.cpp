#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

bool chk[100001];
vector<int> child[100001];
vector<int> picked[100001];
int cnt = 0, idx[100001], ans[100001], to[100001], ans_cnt, in[100001];
bool psb = true;

void set_dfs(int cur, int par){
    idx[cur] = cnt++;
    if(picked[cur].size()) ans[ans_cnt++] = cur;
    chk[cur] = true;

    if(0 <= par){
        if(idx[to[cur]] < par) psb = false;
    }

    for(int i = child[cur].size() - 1; 0 <= i; i--)
        set_dfs(child[cur][i], picked[cur].size() ? idx[cur] : par);
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        child[u].push_back(v);
        in[v]++;
    }

    for(int i = 1; i <= N; i++){
        scanf("%d", &to[i]);
        picked[to[i]].push_back(i);
    }

    for(int i = 1; i <= N; i++){
        if(chk[i] || in[i]) continue;
        set_dfs(i, -1);
    }

    if(psb){
        printf("%d\n", ans_cnt);
        for(int i = ans_cnt - 1; 0 <= i; i--)
            printf("%d\n", ans[i]);
    }
    else printf("-1\n");

    return 0;
}

