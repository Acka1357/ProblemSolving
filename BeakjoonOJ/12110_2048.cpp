//
// Created by Acka on 2017. 8. 7..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int st[20], flag[20];
int N, map[6][20][20], temp1[20][20], temp2[20][20], ans;
char cmd[4] = {' ', 'L', 'R', 'V'}, rcmd[4] = {' ', 'R', 'L', 'V'};

void rotate(char d, int src[][20], int dest[][20]){
    if(d == 'R'){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dest[N - j - 1][i] = src[i][j];
    }
    else if(d == 'L'){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dest[j][N - i - 1] = src[i][j];
    }
    else if(d == 'V'){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dest[N - i - 1][j] = src[i][j];
    }
    else{
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dest[i][j] = src[i][j];
    }
}

void lean_down(int org[][20], int next[][20]){
    for(int j = 0; j < N; j++){
        int idx = 0;
        for(int i = N - 1; i >= 0; i--)
            if(org[i][j]){
                if(idx && st[idx - 1] == org[i][j] && flag[idx - 1] == 0){
                    st[idx - 1] *= 2;
                    flag[idx - 1] = 1;
                }
                else{
                    st[idx] = org[i][j];
                    flag[idx++] = 0;
                }
            }

        for(int i = 0; i < idx; i++)
            next[N - i - 1][j] = st[i];
        for(int i = idx; i < N; i++)
            next[N - i - 1][j] = 0;
    }
}

void take_step(int lcnt){
    for(int i = 0; i < 4; i++){
        rotate(cmd[i], map[lcnt], temp1);
        lean_down(temp1, temp2);
        rotate(rcmd[i], temp2, map[lcnt + 1]);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ans = max(ans, temp2[i][j]);

        if(lcnt < 4) take_step(lcnt + 1);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &map[0][i][j]);
    take_step(0);
    printf("%d\n", ans);
    return 0;
}

