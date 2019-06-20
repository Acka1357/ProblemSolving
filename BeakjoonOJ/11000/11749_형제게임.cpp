//
// Created by Acka on 2017. 8. 1..
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF     0x1f1f1f1f

struct Node{
    int sink, cur, step;
    Node(){}
    Node(int s, int x, int d):sink(s), cur(x), step(d){}
};

struct PNode{
    int cur, step;
    PNode(){}
    PNode(int x, int d):cur(x), step(d){}
    bool operator < (const PNode &A)const{
        return step > A.step;
    }
};

int d[51][3], chkd[51];
bool once[51][51][101], chk[51];
vector<int> radj[51];

int main()
{
    int N, M, a[3];
    scanf("%d %d %d %d %d", &N, &M, &a[0], &a[1], &a[2]);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        radj[v].push_back(u);
    }

    queue<Node> q;
    for(int i = 1; i <= N; i++){
        q.push(Node(i, i, 0));
        once[i][i][0] = true;
    }
    while(!q.empty()){
        int sink = q.front().sink, cur = q.front().cur, step = q.front().step; q.pop();
        for(int i = 0; i < radj[cur].size(); i++){
            int& past = radj[cur][i];
            if(!once[past][sink][step + 1]){
                once[past][sink][step + 1] = true;
                if(step < 100)
                    q.push(Node(sink, past, step + 1));
            }
        }
    }

    memset(d, 0x1f, sizeof(d));
    memset(chkd, 0x1f, sizeof(chkd));

    priority_queue<PNode> pq;
    pq.push(PNode(N, 0));
    d[N][0] = d[N][1] = d[N][2] = chkd[0] = 0;
    while(!pq.empty()){
        int cur = pq.top().cur, step = pq.top().step; pq.pop();
        if(chk[cur]) continue;
        chk[cur] = true;
        for(int past = 1, maxd; past <= N; past++){
            for(int i = 0; i < 3; i++)
                if(once[past][cur][a[i]] && d[past][i] == INF)
                    d[past][i] = step + 1;

            if((maxd = max(d[past][0], max(d[past][1], d[past][2]))) < chkd[past]){
                chkd[past] = maxd;
                pq.push(PNode(past, maxd));
            }
        }
    }

    if(chkd[1] >= INF) printf("IMPOSSIBLE\n");
    else printf("%d\n", chkd[1]);
    return 0;
}

