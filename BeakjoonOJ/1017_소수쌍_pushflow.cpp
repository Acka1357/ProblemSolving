//
// Created by Acka on 2017. 11. 5..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool nop[2001] = {true, true, };

void set_prime(){
    for(int i = 2; i <= 45; i++){
        if(nop[i]) continue;
        for(int j = i * i; j <= 2000; j += i)
            nop[j] = true;
    }
}

struct BTM{
    vector<vector<int> > g;
    vector<int> chk, match;
    int V, step, cnt;

    BTM(int V):V(V), step(0), cnt(0){
        g = vector<vector<int>>(V);
        chk = vector<int>(V, -1);
        match = vector<int>(V, -1);
    }

    void add_edge(int l, int r){ g[l].push_back(r); }

    bool dfs(int v){
        chk[v] = step;
        for(int i = 0; i < g[v].size(); i++){
            int &u = g[v][i], &w = match[u];
            if(w < 0 || (chk[w] != step && dfs(w))){
                match[v] = u, match[u] = v;
                return true;
            }
        }
        return false;
    }

    int max_btm(){
        for(int i = 0; i < V; i++)
            if(match[i] < 0){
                step++;
                if(dfs(i)) cnt++;
            }
        return cnt;
    }
};

int a[50], ans[50];

int main()
{
    set_prime();

    int N; scanf("%d", &N);

    int odd = 0, even = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
        if(a[i] & 1) odd++;
        else even++;
    }
    if(odd != even) return 0 & printf("-1\n");

    BTM btm(N);
    int left = a[0] & 1;
    for(int i = 1; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(!nop[a[i] + a[j]]){
                if((a[i] & 1) == left) btm.add_edge(i , j);
                else btm.add_edge(j, i);
            }

    int idx = 0;
    btm.add_edge(0, -1);
    for(int i = 1; i < N; i++)
        if(!nop[a[0] + a[i]]){
            btm.g[0][0] = i;
            if(btm.match[0] > 0){
                btm.match[0] = btm.match[btm.match[0]] = -1;
                btm.cnt--;
            }
            if(btm.max_btm() == N / 2) ans[idx++] = a[i];
        }

    if(!idx) return 0 & printf("-1\n");

    sort(ans, ans + idx);
    for(int i = 0; i < idx; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
