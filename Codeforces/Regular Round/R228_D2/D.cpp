//
// Created by Acka on 8/8/16.
//

#include <stdio.h>

int cnt[10][10], node[10][10][10];
char ans[1000][1001];

int main()
{
    int idx = 2;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < i; j++) {
            cnt[i][j] = 10;
            for(int k = 0; k < 10; k++)
                node[i][j][k] = idx++;
        }
        for(int j = i; j < 10; j++){
            cnt[i][j] = 1;
            node[i][j][0] = idx++;
        }
    }

    for(int i = 0; i < 1000; i++)
        for(int j = i; j < 1000; j++)
            ans[i][j] = ans[j][i] = 'N';

    int K; scanf("%d", &K);
    for(int i = 0, ten = 1; i < 10; i++, ten *= 10)
        if((K / ten) % 10){
            for(int j = 0; j < 9; j++)
                for(int k = 0; k < cnt[i][j]; k++)
                    for(int l = 0; l < cnt[i][j + 1]; l++)
                        ans[node[i][j][k]][node[i][j + 1][l]] = ans[node[i][j + 1][l]][node[i][j][k]] = 'Y';
            for(int j = 0; j < cnt[i][0]; j++)
                ans[0][node[i][0][j]] = ans[node[i][0][j]][0] = 'Y';
            for(int j = 0; j < cnt[i][9]; j++)
                ans[1][node[i][9][j]] = ans[node[i][9][j]][1] = 'Y';
        }

    printf("%d\n", 1000);
    for(int i = 0; i < 1000; i++)
        printf("%s\n", ans[i]);

    return 0;
}

