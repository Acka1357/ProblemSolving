//
// Created by Acka on 2017. 9. 4..
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <functional>
using namespace std;

vector<int> adj[1001];
int res[200][1000], cnt[1001][1001], in[1001], ans[1000];

int main()
{
    int N, K;
    while(scanf("%d %d", &N, &K) == 2){
        if(N + K == 0) break;

        memset(in, 0, sizeof(in));
        for(int i = 1; i <= N; i++){
            memset(cnt[i], 0, (N +1) * sizeof(cnt[i][0]));
            adj[i].clear();
        }

        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++)
                scanf("%d", &res[i][j]);
            for(int j = 0; j <N; j++)
                for(int k = j +1; k < N; k++)
                    cnt[res[i][j]][res[i][k]]++;
        }

        for(int i = 1; i <= N; i++)
            for(int j = i +1; j <= N; j++){
                if(cnt[i][j] > cnt[j][i]){
                    adj[i].push_back(j);
                    in[j]++;
                }
                else if(cnt[i][j] < cnt[j][i]){
                    adj[j].push_back(i);
                    in[i]++;
                }
            }

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i <= N; i++)
            if(in[i] == 0) q.push(i);

        int idx = 0;
        while(!q.empty()){
            int cur = q.top(); q.pop();
            ans[idx++] = cur;
            for(int i = 0; i < adj[cur].size(); i++)
                if(--in[adj[cur][i]] == 0) q.push(adj[cur][i]);
        }

        if(idx == N){
            for(int i = 0; i < N; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else printf("No solution\n");
    }
    return 0;
}

