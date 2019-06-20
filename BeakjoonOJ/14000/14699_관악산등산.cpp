//
// Created by Acka on 2017. 9. 14..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Shim{
    int idx, h;
    bool operator <(const Shim &A)const{
        return h > A.h;
    }
};

Shim v[5001];
vector<int> adj[5001];
int maxup[5001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &v[i].h);
        v[i].idx = i;
    }
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        if(v[a].h < v[b].h) adj[b].push_back(a);
        else adj[a].push_back(b);
    }

    sort(v + 1, v + N + 1);
    for(int i = 1; i <= N; i++){
        int cur = v[i].idx;
        maxup[cur]++;
        for(int j = 0; j < adj[cur].size(); j++)
            maxup[adj[cur][j]] = max(maxup[adj[cur][j]], maxup[cur]);
    }

    for(int i = 1; i <= N; i++)
        printf("%d\n", maxup[i]);

    return 0;
}
