//
// Created by Acka on 2017. 4. 14..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Crd{
    int r, c;
    Crd(){}
    Crd(int r, int c){
        r = r; c = c;
    }
};

vector<Crd> crd;
bool rchk[9][10], cchk[9][10], rec[9][10];
// rchk[i][j]: i번 row에 j를 썼나?
int map[9][9];

bool set_number(int idx){
    if(idx == crd.size()) return true;

    int r = crd[idx].r, c = crd[idx].c;
    for(int i = 1; i <= 9; i++)
        if(!rchk[r][i] && !cchk[c][i] && !rec[(r / 3) * 3 + c][i]) {
            map[r][c] = i;
            rchk[i][map[i][j]] = cchk[j][map[i][j]] = rec[(i / 3) * 3 + j][map[i][j]] = true;
            if(set_number(idx + 1)) return true;
            rchk[i][map[i][j]] = cchk[j][map[i][j]] = rec[(i / 3) * 3 + j][map[i][j]] = false;
        }
    map[r][c] = 0;
    return false;
}

int main()
{
   for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0){
                crd.push_back(Crd(i, j));
            }
            else rchk[i][map[i][j]] = cchk[j][map[i][j]] = rec[(i / 3) * 3 + j][map[i][j]] = true;
        }

    if(set_number(0)){
        for(int i = 0; i < 9; i++)
    }
    else printf("-1\n");

    return 0;
}
