#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Crd{
    int p1, p2;
    bool operator <(const Crd &o)const{
        return p1 == o.p1 ? p2 < o.p2 : p1 < o.p1;
    }
};
struct Seg{ int o, mn, mx; };

Crd xc[10000], yc[10000];
Seg xseg[10000], yseg[10000];
vector<int> adj[10001];
bool chk[10001];

int dfs(int cur){
    int sum = 1;
    chk[cur] = true;
    for(int &nxt : adj[cur])
        if(!chk[nxt]) sum += dfs(nxt);
    return sum;
}

int main()
{
    int tc, N; for(scanf("%d", &tc); tc--;){
        scanf("%d", &N);
        for(int i = 0, x, y; i < N; i++){
            scanf("%d %d", &x, &y);
            xc[i] = {x, y}; yc[i] = {y, x};
        }

        sort(xc, xc + N); sort(yc, yc + N);

        bool psb = !(N & 1);
        int xcnt = 0, ycnt = 0;
        for(int i = 0; i < N && psb; i += 2){
            if(xc[i].p1 != xc[i + 1].p1 || yc[i].p1 != yc[i + 1].p1){
                psb = false; break;
            }
            xseg[xcnt++] = {xc[i].p1, xc[i].p2, xc[i + 1].p2};
            yseg[ycnt++] = {yc[i].p1, yc[i].p2, yc[i + 1].p2};
        }

        if(!psb){
            printf("NO\n");
            continue;
        }

        memset(chk, false, sizeof(chk));
        for(int i = 0; i < xcnt + ycnt; i++)
            adj[i].clear();

        for(int i = 0; i < xcnt && psb; i++){
            Seg &xs = xseg[i];
            for(int j = 0; j < ycnt; j++){
                Seg &ys = yseg[j];
                if(xs.mn > ys.o || ys.o > xs.mx) continue;
                if(ys.mn > xs.o || xs.o > ys.mx) continue;
                if(ys.o == xs.mn || ys.o == xs.mx || xs.o == ys.mn || xs.o == ys.mx){
                    adj[i].push_back(xcnt + j);
                    adj[xcnt + j].push_back(i);
                    continue;
                }
                psb = false; break;
            }
        }
        printf("%s\n", (psb && dfs(1) == xcnt + ycnt) ? "YES" : "NO");
    }
    return 0;
}
