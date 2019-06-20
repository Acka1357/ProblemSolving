//
// Created by Acka on 2017. 5. 24..
//

#include <stdio.h>

int acc[1025][1025];

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &acc[i][j]);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            printf("%3d ", acc[i][j]);
        printf("\n");
    }
    int r1, c1, r2, c2;
    while (M--){
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        printf("%d\n", acc[r2][c2] + acc[r1 - 1][c1 - 1] - acc[r1 - 1][c2] - acc[r2][c1 - 1]);
    }

    return 0;
}
