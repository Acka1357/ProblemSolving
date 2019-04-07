//
// Created by Acka on 9/14/16.
//

#include <stdio.h>

int main()
{
    int tc; for(scanf("%d", &tc); tc--;) {
        int N, K; scanf("%d %d", &N, &K);

        char name[100][4];
        for(int i = 0; i < N; i++)
            scanf("%s", name[i]);

        int mat[100][100];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &mat[i][j]);

        int ans[100][100];
        int mult[100][100] = {1, 0,};

        while(K--){
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++){
                    ans[i][j] = 0;
                    for(int k = 0; k < N; k++)
                        ans[i][j] += mult[i][k] * mat[k][j];
                }
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    mult[i][j] = ans[i][j];
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

