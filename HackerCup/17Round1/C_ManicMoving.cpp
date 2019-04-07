/*
//
// Created by Acka on 2017. 1. 15..
//

#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

struct Node{
    int idx, cur, stat;
    long long int cost;
    Node(){} Node(int i, int v, int s, long long c):idx(i), cur(v), stat(s), cost(c){}
    bool operator < (const Node &A)const{
        return cost == A.cost ? (idx == A.idx ? stat < A.stat: A.idx < idx) : A.cost < cost;
    }
};

bool chk[5001][101][3];
long long int d[5001][101][3];
int mind[101][101], f[5001][2];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/manic_moving.txt", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/C.txt", "w", stdout);
    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int N, M, K; scanf("%d %d %d", &N, &M, &K);
        // 100, 5000, 5000

        memset(mind, 0xff, sizeof(mind));
        for(int i = 0, u, v, c; i < M; i++){
            scanf("%d %d %d", &u, &v, &c);
            if(mind[u][v] < 0 || c < mind[u][v]) mind[u][v] = mind[v][u] = c;
        }

        for(int i = 1; i <= N; i++)
            mind[i][i] = 0;

        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++){
                if(mind[i][k] < 0) continue;
                for(int j = 1; j <= N; j++)
                    if(0 <= mind[k][j]){
                        if(mind[i][j] < 0) mind[i][j] = mind[i][k] + mind[k][j];
                        else if(mind[i][k] + mind[k][j] < mind[i][j]) mind[i][j] = mind[i][k] + mind[k][j];
                    }
            }

        for(int i = 1; i <= K; i++)
            scanf("%d %d", &f[i][0], &f[i][1]);

        long long int ans = -1;
        memset(chk, false, sizeof(chk));
        memset(d, 0xff, sizeof(d));
        priority_queue<Node> pq; pq.push(Node(0, 1, 0, 0));
        d[0][1][0] = 0;
        while(!pq.empty()){
            int idx = pq.top().idx, cur = pq.top().cur, stat = pq.top().stat;
            long long int cost = pq.top().cost; pq.pop();

            if(idx == K && !stat){
                ans = cost; break;
            }

            if(chk[idx][cur][stat]) continue;
            else chk[idx][cur][stat] = true;

            if(stat == 0 && idx < K){
                int next = f[idx + 1][0], nc = cost + mind[cur][next];
                if(0 <= mind[cur][next] && (d[idx][next][1] < 0 || nc < d[idx][next][1])) {
                    pq.push(Node(idx, next, 1, nc));
                    d[idx][next][1] = nc;
                }
            }
            else if(stat == 1){
                int next = f[idx + 1][1], nc = cost + mind[cur][next];
                if(0 <= mind[cur][next] && (d[idx + 1][next][0] < 0 || nc < d[idx + 1][next][0])) {
                    pq.push(Node(idx + 1, next, 0, nc));
                    d[idx + 1][next][0] = nc;
                }

                if(idx < K) {
                    next = f[idx + 2][0]; nc = cost + mind[cur][next];
                    if (0 <= mind[cur][next] && (d[idx][next][2] < 0 || nc < d[idx][next][2])) {
                        pq.push(Node(idx, next, 2, nc));
                        d[idx][next][2] = nc;
                    }
                }
            }
            else{
                int next = f[idx + 1][1], nc = cost + mind[cur][next];
                if(0 <= mind[cur][next] && (d[idx + 1][next][1] < 0 || nc < d[idx + 1][next][1])) {
                    pq.push(Node(idx + 1, next, 1, nc));
                    d[idx + 1][next][1] = nc;
                }
            }
        }

        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}
*/
