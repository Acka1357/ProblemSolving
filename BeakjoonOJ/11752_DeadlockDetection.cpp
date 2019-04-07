//
// Created by Acka on 2017. 11. 17..
//

#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

int P, R, T;
int amt[301], need[301][301], who[200001], what[200001];
int cur[301][301], rem[301];

bool is_deadlock(int t){
    memset(cur, 0, sizeof(cur));
    for(int i = 1; i <= t; i++)
        cur[who[i]][what[i]]++;

    for(int i = 1; i <= R; i++)
        rem[i] = amt[i];

    queue<int> q;
    for(int i = 1; i <= P; i++){
        bool rel = true, allz = true;
        for(int j = 1; j <= R; j++){
            if(cur[i][j]) allz = false;
            if(cur[i][j] < need[i][j]) rel = false;
        }
        if(allz) continue;
        if(!rel){
            for(int j = 1; j <= R; j++)
                rem[j] -= cur[i][j];
            q.push(i);
        }
    }

    int cnt = q.size();
    while(!q.empty() && cnt){
        int p = q.front(); q.pop();
        bool psb = true;
        for(int i = 1; i <= R; i++)
            if(need[p][i] > rem[i] + cur[p][i]){
                psb = false;
                break;
            }
        if(psb){
            for(int i = 1; i <= R; i++)
                rem[i] += cur[p][i];
            cnt = q.size();
        }
        else q.push(p), cnt--;
    }

    return !q.empty();
}

int main()
{
    scanf("%d %d %d", &P, &R, &T);
    for(int i = 1; i <= R; i++)
        scanf("%d", &amt[i]);
    for(int i = 1; i <= P; i++)
        for(int j = 1; j <= R; j++)
            scanf("%d", &need[i][j]);
    for(int i = 1; i <= T; i++)
        scanf("%d %d", &who[i], &what[i]);

    int l = 1, r = T, m, ans = -1;
    while(l <= r){
        m = (l + r) / 2;
        if(is_deadlock(m)) ans = m, r = m - 1;
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}
