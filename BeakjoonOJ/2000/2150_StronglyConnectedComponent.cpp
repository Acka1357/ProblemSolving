#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool chk[10001];
int V, E, idx[10001], low[10001], cnt, ccnt;
vector<int> adj[10001], member[10001];
stack<int> st;

void dfs(int cur){
    idx[cur] = low[cur] = ++cnt;
    st.push(cur);

    chk[cur] = true;
    for(int i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(idx[next] && chk[next]) low[cur] = min(low[cur], idx[next]);
        else if(!idx[next]){
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }
    }

    if(idx[cur] == low[cur]){
        while(st.top() != cur){
            member[ccnt].push_back(st.top());
            chk[st.top()] = false;
            st.pop();
        }
        member[ccnt].push_back(cur);
        chk[cur] = false;
        st.pop();

        sort(member[ccnt].begin(), member[ccnt].end());
        ccnt++;
    }
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i = 0, u, v; i < E; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i = 1; i <= V; i++)
        if(!idx[i]) dfs(i);

    sort(member, member + ccnt);

    printf("%d\n", ccnt);
    for (int i = 0; i < ccnt; i++){
        for (int j = 0; j < member[i].size(); j++)
            printf("%d ", member[i][j]);
        printf("-1\n");
    }

    return 0;
}
