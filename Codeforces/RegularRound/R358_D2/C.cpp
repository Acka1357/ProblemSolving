#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
    int p, c;
    Edge(){} Edge(int p, int c):p(p), c(c){}
};

struct Return{
    int sub, cut;
    Return(){} Return(int s, int c):sub(s), cut(c){}
};

int N, a[100001], ans;
vector<Edge> adj[100001];

Return chk_len(int cur, long long int len){
    int subsum = 1, cutsum = 0;

    Return ret;
    for(int i = adj[cur].size() - 1; 0 <= i; i--) {
        ret = chk_len(adj[cur][i].p, len < 0 ? adj[cur][i].c : len + adj[cur][i].c);
        subsum += ret.sub;
        cutsum += ret.cut;
    }

    ret.sub = subsum; ret.cut = cutsum;
    if(cur != 1 && a[cur] < len){
        ret.cut = ret.sub;
    }

    return ret;
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    for(int i = 2, p, c; i <= N; i++) {
        scanf("%d %d", &p, &c);
        adj[p].push_back(Edge(i, c));
    }

    Return ret = chk_len(1, 0);
    printf("%d\n", ret.cut);
    return 0;
}

