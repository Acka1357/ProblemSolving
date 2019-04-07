//
// Created by Acka on 9/1/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

#define INF	987654321

struct Edge{
   int to, cap, rev;
   Edge(){} Edge(int t, int c, int r) : to(t), cap(c), rev(r){}
};

struct MaxFlow{
   vector< vector<Edge> > G;
   vector<bool> used;

   MaxFlow(){}
   MaxFlow(int n){
       G.resize(n); used.resize(n);
   }

   void add_edge(int from, int to, int cap){
       G[from].push_back(Edge(to, cap, G[to].size()));
       G[to].push_back(Edge(from, 0, G[from].size() - 1));
   }

   int dfs(int v, int t, int f){
       if (v == t)  return f;
       used[v] = true;

       for (int i = 0, sz = G[v].size(); i < sz; i++){
           Edge &e = G[v][i];
           if (!used[e.to] && (e.cap > 0)){
               int d = dfs(e.to, t, (f < e.cap ? f : e.cap));
               if (d > 0) {
                   e.cap -= d; G[e.to][e.rev].cap += d;
                   return d;
               }
           }
       }
       return 0;
   }

   int get_max(int src, int sink){
       int sum = 0, flow = 0;
       while (flow = dfs(src, sink, INF)){
           sum += flow;
           fill(used.begin(), used.end(), false);
       }
       return sum;
   }
};

int main()
{
   int tc; for(scanf("%d", &tc); tc--;){
       int N, M; scanf("%d %d", &N, &M);

       int src = 0, sink = N * 500 + M + 1, sum = 0;
       MaxFlow mf(sink + 1);
       for(int i = 1; i <= N; i++)
           for (int j = (i - 1) * 500 + 1; j <= i * 500; j++)
               mf.add_edge(src, j, 1);

       int base = N * 500;
       for(int i = 1, s, w, d; i <= M; i++){
           scanf("%d %d %d", &s, &w, &d);
           for(int j = 1; j <= N; j++)
               for(int k = s; k <= d; k++)
                   mf.add_edge(500 * (j - 1) + k, N * 500 + i, 1);

           mf.add_edge(N * 500 + i, sink, w);
           sum += w;
       }

       if(mf.get_max(src, sink) == sum){
           for(int i = 1; i <= M; i++){

           }
       }
       else printf("0\n");
   }
   return 0;
}