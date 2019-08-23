//
// Created by Acka on 7/19/16.
//

#include <stdio.h>

int rcnt[1000], ccnt[1000];
char map[1000][1001];

int main()
{
    int R, C; scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
        scanf("%s", map[i]);

    int sum = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(map[i][j] == '*'){
                rcnt[i]++; ccnt[j]++;
                sum++;
            }

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if((rcnt[i] + ccnt[j] - (map[i][j] == '*' ? 1 : 0)) == sum) {
                printf("YES\n%d %d\n", i + 1, j + 1);
                return 0;
            }

    printf("NO\n");
    return 0;
}

