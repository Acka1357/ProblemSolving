//
// Created by Acka on 9/2/16.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sol[10];
int N, M, ans = -1, p[11];

void make_team(int cur, int team_cnt, int sol_cnt){
    if(cur == M){
        if(sol_cnt == N){
            if(ans < 0) ans = team_cnt;
            else ans = min(ans, team_cnt);
        }
        return ;
    }

    make_team(cur + 1, team_cnt, sol_cnt);

    int add = 0;
    for(int i = 0; i < sol[cur].size(); i++){
        if(!p[sol[cur][i]]) add++;
        p[sol[cur][i]]++;
    }
    make_team(cur + 1, team_cnt + 1, sol_cnt + add);

    for(int i = 0; i < sol[cur].size(); i++)
        p[sol[cur][i]]--;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0, x, y; i < M; i++){
        scanf("%d", &x);
        while(x--){
            scanf("%d", &y);
            sol[i].push_back(y);
        }
    }

    make_team(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
