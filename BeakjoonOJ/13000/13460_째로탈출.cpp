//
// Created by Acka on 2017. 4. 6..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Info{
    int rr, rc, br, bc, step;
    Info(){}
    Info(int rr, int rc, int br, int bc, int s):rr(rr),rc(rc), br(br), bc(bc), step(s){}
};

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
bool chk[10][10][10][10];

int main()
{
    int R, C; scanf("%d %d", &R, &C);

    char map[10][11];
    for(int i = 0; i < R; i++)
        scanf("%s", map[i]);

    int rr, rc, br, bc;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            if(map[i][j] == 'R') rr = i, rc = j;
            else if(map[i][j] == 'B') br = i, bc = j;
        }

    queue<Info> q;
    q.push(Info(rr, rc, br, bc, 0));
    chk[rr][rc][br][bc] = true;

    int ans = -1;
    while(!q.empty() && ans < 0){
        if(10 <= q.front().step) break;
        for(int i = 0; i < 4; i++){
            bool rchk = false, bchk = false;
            rr = q.front().rr, rc = q.front().rc, br = q.front().br, bc = q.front().bc;
            while(map[rr + dr[i]][rc + dc[i]] != '#'){
                rr += dr[i], rc += dc[i];
                if(map[rr][rc] == 'O') rchk = true;
            }
            while(map[br + dr[i]][bc + dc[i]] != '#'){
                br += dr[i], bc += dc[i];
                if(map[br][bc] == 'O') bchk = true;
            }

            if(bchk) continue;
            else if(rchk){
                ans = q.front().step + 1;
                break;
            }
            if(rr == br && rc == bc){
                if(i == 0){ // rgiht
                    if(q.front().rc < q.front().bc) rc--;
                    else bc--;
                }
                else if(i == 1){    // down
                    if(q.front().rr < q.front().br) rr--;
                    else br--;
                }
                else if(i == 2){    // left
                    if(q.front().rc < q.front().bc) bc++;
                    else rc++;
                }
                else{   //up
                    if(q.front().rr < q.front().br) br++;
                    else rr++;
                }
            }
            if(!chk[rr][rc][br][bc]){
                q.push(Info(rr, rc, br, bc, q.front().step + 1));
                chk[rr][rc][br][bc] = true;
            }
        }
        q.pop();
    }

    printf("%d\n", ans);
    return 0;
}

