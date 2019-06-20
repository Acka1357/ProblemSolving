#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

struct Edge{
    int u, v;
    Edge(){} Edge(int u, int v):u(u), v(v){}
};

struct Info{
    int p, ecnt, ncnt;
    Info(){} Info(int p, int e, int n):p(p), ecnt(e), ncnt(n){}
    bool is_complete(){
        return (ecnt << 1) == ncnt * (ncnt - 1);
    }
};

Info node[1000];
queue<Edge> edge[1000001];
queue<int> q;
int chk[1000];

int find(int x){
    return node[x].p == x ? x : find(node[x].p);
}

void link(int px, int py){
    if(px == py) return ;
    node[px].ecnt += node[py].ecnt;
    node[px].ncnt += node[py].ncnt;
    node[py].p = px;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        for(int i = 0, x; i < N; i++)
            for(int j = i + 1; j < N; j++) {
                scanf("%d", &x);
                edge[x].push(Edge(i, j));
            }

        for(int i = 0; i < N; i++)
            node[i] = Info(i, 0, 1);

        memset(chk, 0, sizeof(chk));
        int ans = 0;
        for(int i = 1; i <= 1000000; i++){
            while(!edge[i].empty()){
                int px = find(edge[i].front().u), py = find(edge[i].front().v); edge[i].pop();
                link(px, py);
                node[px].ecnt++;
                if(node[px].ncnt != N && node[px].ncnt != 1 && node[px].is_complete() && chk[px] != i){
                    chk[px] = i;
                    ans++;
                }
            }
            while(!q.empty()){
                int p = find(q.front()); q.pop();
                if(chk[p] == i) continue;
                if(node[p].ncnt != N && node[p].ncnt != 1 && node[p].is_complete()){
                    chk[p] = i;
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
