#include <stdio.h>

int main()
{
    int N, M, K; scanf("%d %d", &N, &M);

    int a[100][100], b[100][100];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &a[i][j]);

    scanf("%*d %d", &K);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            scanf("%d", &b[i][j]);

    int ans[100][100] = {0,};
    for(int i = 0; i < N; i++)
        for(int j = 0; j < K; j++)
            for(int k = 0; k < M; k++)
                ans[i][j] += a[i][k] * b[k][j];

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    return 0;
}
