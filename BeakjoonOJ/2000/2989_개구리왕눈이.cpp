//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>
using namespace std;

struct Flow{
    int x, y, k;
};

Flow f[300000];

struct Order{
    int idx;
    Order(){} Order(int i):idx(i){}
    bool operator <(const Order &A)const{
        return f[idx].x == f[A.idx].x ? f[idx].y < f[A.idx].y : f[idx].x < f[A.idx].x;
    }
};

int d[300000][3], past[300000][3], nyi[100001];
vector<Order> xs[100001], ys[100001];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/2989_sniper.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/2989_Acka.out", "w", stdout);
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &f[i].x, &f[i].y, &f[i].k);
        xs[f[i].x].push_back(Order(i));
        ys[f[i].y].push_back(i);
    }

    for(int i = 0; i <= 100000; i++){
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }

    memset(d, 0xff, sizeof(d));
    d[0][0] = f[0].k;
    for(int x = 0; x <= 100000; x++)
        for(int i = 0; i < xs[x].size(); i++){
            int &idx = xs[x][i].idx, &y = f[idx].y, &k = f[idx].k;
            if(i != xs[x].size() - 1){
                int &nidx = xs[x][i + 1].idx, &nk = f[nidx].k;
                if(d[idx][0] >= K){
                    if(d[nidx][0] < d[idx][0] - K + nk){
                        d[nidx][0] = d[idx][0] - K + nk;
                        past[nidx][0] = idx;
                    }
                    if(d[nidx][1] < d[idx][0] - K){
                        d[nidx][1] = d[idx][0] - K;
                        past[nidx][1] = idx;
                    }
                }
                if(d[idx][1] >= 0){
                    if(d[nidx][1] < d[idx][1]){
                        d[nidx][1] = d[idx][1];
                        past[nidx][1] = past[idx][1];
                    }
                    if(d[nidx][0] < d[idx][1] + nk){
                        d[nidx][0] = d[idx][1] + nk;
                        past[nidx][0] = past[idx][1];
                    }
                }
            }
            if(nyi[y] != ys[y].size() - 1){
                nyi[y]++;
                int &nidx = ys[y][nyi[y]].idx, &nk = f[nidx].k;
                if(d[idx][0] >= K){
                    if(d[nidx][0] < d[idx][0] - K + nk){
                        d[nidx][0] = d[idx][0] - K + nk;
                        past[nidx][0] = idx;
                    }
                    if(d[nidx][2] < d[idx][0] - K){
                        d[nidx][2] = d[idx][0] - K;
                        past[nidx][2] = idx;
                    }
                }
                if(d[idx][2] >= 0){
                    if(d[nidx][2] < d[idx][2]){
                        d[nidx][2] = d[idx][2];
                        past[nidx][2] = past[idx][2];
                    }
                    if(d[nidx][0] < d[idx][2] + nk){
                        d[nidx][0] = d[idx][2] + nk;
                        past[nidx][0] = past[idx][2];
                    }
                }
            }
        }

    stack<int> st;
    for(int cur = N - 1; cur; cur = past[cur][0])
        st.push(cur);

    printf("%d\n%d\n%d %d\n", d[N - 1][0], st.size() + 1, f[0].x, f[0].y);
    while(!st.empty()){
        printf("%d %d\n", f[st.top()].x, f[st.top()].y);
        st.pop();
    }

    return 0;
}

