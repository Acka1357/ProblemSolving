//
// Created by Acka on 2017. 12. 16..
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#include <memory.h>
using namespace std;

vector<char*> hasn[20];
char num[200][11];
char name[20][11];
bool chk[20][200];
int cnt[20], len[20][200];

bool is_suf(char *cur, char *suf, int lc, int ls){
    if(lc <= ls) return false;
    for(int i = 1; i <= ls; i++)
        if(cur[lc - i] != suf[ls - i]) return false;
    return true;
}

int main()
{
    int N; scanf("%d", &N);

    int nidx = 0, numi = -1;
    for(int i = 0; i < N; i++){
        scanf("%s", name[nidx]);
        int curidx = nidx;
        for(int j = 0; j < nidx; j++)
            if(strcmp(name[nidx], name[j]) == 0){
                curidx = j;
                break;
            }

        int curcnt; scanf("%d", &curcnt);
        cnt[curidx] += curcnt;
        for(int j = 0; j < curcnt; j++){
            scanf("%s", num[++numi]);
            len[curidx][hasn[curidx].size()] = strlen(num[numi]);
            hasn[curidx].push_back(num[numi]);
        }
        if(curidx == nidx) nidx++;
    }

    printf("%d\n", nidx);
    for(int i = 0; i < nidx; i++){
        int amt = cnt[i];
        for(int j = 0; j < amt; j++){
            if(chk[i][j]) continue;
            for(int k = j + 1; k < amt; k++)
                if(strcmp(hasn[i][j], hasn[i][k]) == 0){
                    chk[i][k] = true;
                    cnt[i]--;
                }
        }
        for(int j = 0; j < amt; j++){
            if(chk[i][j]) continue;
            for(int k = 0; k < amt; k++){
                if(chk[i][k]) continue;
                if(is_suf(hasn[i][j], hasn[i][k], len[i][j], len[i][k])){
                    chk[i][k] = true;
                    cnt[i]--;
                }
            }
        }

        printf("%s %d ", name[i], cnt[i]);
        for(int j = 0; j < amt; j++)
            if(!chk[i][j]) printf("%s ", hasn[i][j]);
        printf("\n");
    }

    return 0;
}

