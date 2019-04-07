//
// Created by Acka on 2017. 4. 23..
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

char ans[1001], alp[6] = {'R', 'Y', 'B', 'O', 'G', 'V'};
int idx[256], cnt[7], ridx[256];

void print_set(char x){
    int i1 = idx[x], i2 = ridx[x];
    if(!cnt[i2]) return ;
    while(cnt[i2]){
        printf("%c%c", alp[i1], alp[i2]);
        cnt[i2]--;
    }
    printf("%c", alp[i1]);
}

int main()
{
    idx['R'] = 0; idx['Y'] = 1; idx['B'] = 2;
    idx['O'] = 3; idx['G'] = 4; idx['V'] = 5;
    ridx['R'] = idx['G']; ridx['Y'] = idx['V']; ridx['B'] = idx['O'];
    ridx['G'] = idx['R']; ridx['V'] = idx['Y']; ridx['O'] = idx['B'];
//    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1B/B-small-attempt0.in", "r", stdin);
//    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1B/B.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N; scanf("%d", &N);
        scanf("%d %d %d %d %d %d", &cnt[idx['R']], &cnt[idx['O']], &cnt[idx['Y']], &cnt[idx['G']], &cnt[idx['B']], &cnt[idx['V']]);

        bool psb = true;

        int org_noz = 0, comb_noz;
        for(int i = 0; i < 3 ;i++)
            if(cnt[i]) org_noz++;
        for(int i = 3; i < 6; i++)
            if(cnt[i]) comb_noz++;

        if(org_noz + comb_noz == 2 && (N & 1)) psb = false;
        if(org_noz == 1 && comb_noz == 1 && !(N & 1)){
            int org , comb;
            for(int i = 0; i < 3; i++)
                if(cnt[i]) org = i;
            for(int i = 3; i < 6; i++)
                if(cnt[i]) comb = i;
            if(cnt[org] == cnt[comb]){
                while(cnt[org]){
                    printf("%c%c", alp[org], alp[comb]);
                    cnt[org]--;
                }
                printf("\n");
                continue;
            }
        }

        if(cnt[idx['O']] && cnt[idx['B']] < cnt[idx['O']] * 2 - 1) psb = false;
        if(cnt[idx['G']] && cnt[idx['R']] < cnt[idx['G']] * 2 - 1) psb = false;
        if(cnt[idx['V']] && cnt[idx['Y']] < cnt[idx['V']] * 2 - 1) psb = false;

        cnt[idx['R']] -= cnt[idx['G']] * 2 - 1;
        cnt[idx['Y']] -= cnt[idx['V']] * 2 - 1;
        cnt[idx['B']] -= cnt[idx['O']] * 2 - 1;

        int i1 = 0, i2 = 1, i3 = 2;
        if(cnt[1] <= cnt[0] && cnt[2] <= cnt[0]){
            i1 = 0;
            if(cnt[1] < cnt[2]) i2 = 2, i3 = 1;
            else i2 = 1, i3 = 2;
        }
        else if(cnt[0] <= cnt[1] && cnt[2] <= cnt[1]){
            i1 = 1;
            if(cnt[0] < cnt[2]) i2 = 2, i3 = 0;
            else i2 = 0, i3 = 2;
        }
        else{
            i1 = 2;
            if(cnt[0] < cnt[1]) i2 = 1, i3 = 0;
            else i2 = 0, i3 = 1;
        }

        if(cnt[i2] + cnt[i3] < cnt[i1] - 1) psb = false;

        printf("Case #%d: \n", tc);
        if(!psb){
            printf("IMPOSSIBLE\n");
            continue;
        }

        int same = 0;
        if(cnt[i1] == cnt[i2]) same = 1;

        int sum = cnt[i1] + cnt[i2] + cnt[i3];
        int com = cnt[i2] + cnt[i3] - cnt[i1] - same;
        while(cnt[i1]){
            printf("%c", alp[i1]);
            cnt[i1]--;
            if(cnt[i2]){
                printf("%c", alp[i2]);
                cnt[i2]--;
            }
            if(cnt[i2] <= com && cnt[i3]){
                printf("%c", alp[i3]);
                cnt[i3]--;
            }
            printf("!");
        }

        if(alp[i1] == 'R'){
            if(alp[i3] == 'Y') {
                print_set('B');
                print_set('R');
                print_set('Y');
            }
            else{
                print_set('Y');
                print_set('R');
                print_set('B');
            }
        }
        else if(alp[i1] == 'Y'){
            if(alp[i3] == 'R') {
                print_set('B');
                print_set('Y');
                print_set('R');
            }
            else{
                print_set('R');
                print_set('Y');
                print_set('B');
            }
        }
        else{
            if(alp[i3] == 'R') {
                print_set('Y');
                print_set('B');
                print_set('R');
            }
            else{
                print_set('R');
                print_set('B');
                print_set('Y');
            }
        }
        printf("\n");
    }
    return 0;
}

