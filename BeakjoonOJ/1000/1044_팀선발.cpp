//
// Created by Acka on 2017. 7. 28..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long absx(long long x){
    return x < 0 ? -x : x;
}

struct A_Team{
    int memb;
    long long scr;
    A_Team(){}
    A_Team(int m, long long s):memb(m), scr(s){}
    bool operator < (const A_Team &A)const{
        return scr == A.scr ? memb > A.memb : scr < A.scr;
    }
};

vector<A_Team> team[2][19];
long long tscr[2][36];
int N, half;

void make_team(int tn, int idx, int memb, int cnt, long long scr){
    if(idx == (tn + 1) * half){
        team[tn][cnt].push_back(A_Team(memb, scr));
        return ;
    }

    make_team(tn, idx + 1, (memb << 1) + 1, cnt + 1, scr + tscr[0][idx]);
    make_team(tn, idx + 1, memb << 1, cnt, scr - tscr[1][idx]);
}

void set_team(int tn){
    make_team(tn, tn * half, 0, 0, 0);

    for(int cnt = 0; cnt <= half; cnt++){
        sort(team[tn][cnt].begin(), team[tn][cnt].end());
        int wcnt = team[tn][cnt].size(), ucnt = 1;
        for(int i = 1; i < wcnt; i++)
            if(team[tn][cnt][i].scr != team[tn][cnt][i - 1].scr)
                team[tn][cnt][ucnt++] = team[tn][cnt][i];

        team[tn][cnt].resize(ucnt);
    }
}

long long ans = 1ll << 61;
int ans1, ans2;

void combine_team(vector<A_Team> &team1, vector<A_Team> &team2){
    int i2 = team2.size() - 1;
    long long res, res2, sum;
    for(int i1 = 0; i1 < team1.size(); i1++){
        res = absx(team1[i1].scr + team2[i2].scr); res2 = team2[i2].memb;
        while(0 < i2 && (sum = team1[i1].scr + team2[i2].scr) >= 0){
            if(A_Team(team2[i2].memb, sum) < A_Team(res2, res)){
                res = sum;
                res2 = team2[i2].memb;
            }
            if(1 < i2) i2--; else break;
        }

        if(i2 < team2.size() - 1 && team1[i1].scr + team2[i2].scr < 0) i2++;
        if(0 < i2 && A_Team(team2[i2 - 1].memb, absx(team1[i1].scr + team2[i2 - 1].scr)) < A_Team(res2, res)){
            res = absx(team1[i1].scr + team2[i2 - 1].scr);
            res2 = team2[i2 - 1].memb;
        }

        if(A_Team(team1[i1].memb, res) < A_Team(ans1, ans)){
            ans = res;
            ans1 = team1[i1].memb;
            ans2 = res2;
        }
    }
}

int main()
{
    scanf("%d", &N); half = N / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < N; j++)
            scanf("%lld", &tscr[i][j]);

    set_team(0); set_team(1);

    for(int cnt = 0; cnt <= half; cnt++)
        combine_team(team[0][cnt], team[1][half - cnt]);

    for(int bit = 1 << (N / 2 - 1); bit; bit >>= 1)
        printf("%d ", ans1 & bit ? 1 : 2);
    for(int bit = 1 << (N / 2 - 1); bit; bit >>= 1)
        printf("%d ", ans2 & bit ? 1 : 2);
    printf("\n");

    return 0;
}

