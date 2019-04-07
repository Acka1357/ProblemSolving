//
// Created by Acka on 2017. 8. 1..
//

#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int par[500001], h[500001];

int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void link(int x, int y){
    int px = find(x), py = find(y);
    if(px == py) return ;
    if(h[px] < h[py]) par[px] = py;
    else par[py] = px;
}

map<int, int> mp;
int act[500001], idx, out[500001];
vector<int> adj[500001];
bool chk[500001];

int get_idx(int l){
    if(mp.count(l)) return mp[l];
    ++idx;
    act[idx] = h[idx] = l;
    mp[l] = par[idx] = idx;
    return idx;
}

int set_degree(int cur, int past){
    chk[cur] = true;

    int ret = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        int &next = adj[cur][i];
        if(next == past) continue;

        if(chk[next]){
            if(ret > 0) out[next]++;
            ret = -1;
            continue;
        }

        int res = set_degree(next, cur);
        if(res > 0) out[cur]++;
        else{
            out[next]++;
            ret = -1;
        }
    }

    return ret;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, s, t; i < N; i++){
        scanf("%d %d", &s, &t);
        s = get_idx(s), t = get_idx(t);
        adj[s].push_back(t);
        adj[t].push_back(s);
        link(s, t);
    }

    for(int i = 1; i <= idx; i++)
        if(!chk[i]) set_degree(find(i), 0);

    long long ans = 0;
    for(int i = 1; i <= idx; i++)
        ans += (long long)out[i] * h[i];

    printf("%lld\n", ans);
    return 0;
}

