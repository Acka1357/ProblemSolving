//
// Created by Acka on 2017. 1. 16..
//

/*
#include <stdio.h>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(){} Edge(int t, int c):to(t), cost(c){}
};

struct Node{
    long long int idx, cur, cost, stat;
    Node(){} Node(long long i, long long v, long long c, long long s):idx(i), cur(v), cost(c), stat(s){}
    bool operator < (const Node &A)const{
        return cost == A.cost ? (idx == A.idx ? stat < A.stat: A.idx < idx) : A.cost < cost;
    }
};

bool chk[5003][103][3];
int f[5003][2];
long long int d[5003][103][3];
vector<Edge> adj[103];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/c_test.in", "r", stdin);
    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int N, M, K; scanf("%d %d %d", &N, &M, &K);
        // 100, 5000, 5000

        for(int i = 1; i <= N; i++)
            adj[i].clear();

        for(int i = 0, u, v, c; i < M; i++){
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(Edge(v, c));
            adj[v].push_back(Edge(u, c));
        }

        for(int i = 1; i <= K; i++)
            scanf("%d %d", &f[i][0], &f[i][1]);

        long long int ans = -1;
        memset(chk, false, sizeof(chk));
        memset(d, 0x3f, sizeof(d));
        d[1][1][0] = 0;
        priority_queue<Node> q; q.push(Node(1, 1, 0, 0));
        while(!q.empty()){
            long long int idx = q.top().idx, cur = q.top().cur, cost = q.top().cost, stat = q.top().stat; q.pop();
            if(K < idx){ ans = cost; break; }

            if(chk[idx][cur][stat]) continue;
            else chk[idx][cur][stat] = true;

            if(stat && f[idx][1] == cur){
                if(cost < d[idx + 1][cur][stat - 1]){
                    d[idx + 1][cur][stat - 1] = cost;
                    q.push(Node(idx + 1, cur, cost, stat - 1));
                }
            }
            if(stat < 2 && f[idx + stat][0] == cur){
                if(cost < d[idx][cur][stat + 1]){
                    d[idx][cur][stat + 1] = cost;
                    q.push(Node(idx, cur, cost, stat + 1));
                }
            }

            for(int i = 0; i < adj[cur].size(); i++){
                int next = adj[cur][i].to, nc = cost + adj[cur][i].cost;
                if(nc < d[idx][next][stat]){
                    d[idx][next][stat] = nc;
                    q.push(Node(idx, next, nc, stat));
                }
            }
        }

        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}
 */