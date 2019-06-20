//
// Created by Acka on 2017. 7. 13..
//

#include <stdio.h>

#define BASE        60
#define MAX_SCORE   120

const double eps = 1e-10;
const int add[6] = {3, 2, 1, 0, -1, -3};
const double mult[6] = {1.0/16, 1.0/8, 1.0/4, 3.0/8, 1.0/8, 1.0/16};
double pb[21][121];

int main()
{
    printf("Round   A wins    B wins    Tie\n");

    pb[0][BASE] = 100;
    for(int i = 1; i <= 20; i++){
        for(int j = 0; j <= MAX_SCORE; j++){
            if(pb[i - 1][j] < eps) continue;
            for(int k = 0; k < 6; k++)
                pb[i][j + add[k]] += pb[i - 1][j] * mult[k];
        }

        double win = 0;
        for(int j = BASE + 1; j <= MAX_SCORE; j++)
            win += pb[i][j];

        printf("%5d%10.4lf%%%9.4lf%%%9.4lf%%\n", i, win, 100 - win - pb[i][BASE], pb[i][BASE]);
    }
    return 0;
}
