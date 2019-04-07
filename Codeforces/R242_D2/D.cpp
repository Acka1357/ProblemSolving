//
// Created by Acka on 2017. 8. 7..
//

#include <stdio.h>

int N, M, T, P, U, D;
int ans, ansr1, ansc1, ansr2, ansc2;
int map[301][301];
int left[301][301], right[301][301], top[301][301], btm[301][301];

int absx(int x){
    return x < 0 ? -x : x;
}

int add(int past, int next){
    return past == next ? P : (past < next ? U : D);
}

int main() {
    scanf("%d %d %d %d %d %d", &N, &M, &T, &P, &U, &D);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    for(int i = 1; i <= N; i++)
        for(int j = 2; j <= M; j++){
            right[i][j] = right[i][j - 1] + add(map[i][j - 1], map[i][j]);
        }
    for(int i = 1; i <= N; i++)
        for(int j = M - 1; j >= 1; j--){
            left[i][j] = left[i][j + 1] + add(map[i][j + 1], map[i][j]);
        }
    for(int i = N - 1; i >= 1; i--)
        for(int j = 1; j <= M; j++){
            top[i][j] = top[i + 1][j] + add(map[i + 1][j], map[i][j]);
        }
    for(int i = 2; i <= N; i++)
        for(int j = 1; j <= M; j++){
            btm[i][j] = btm[i - 1][j] + add(map[i - 1][j], map[i][j]);
        }

    for(int r1 = 1; r1 <= N; r1++)
        for(int c1 = 1; c1 <= M; c1++)
            for(int r2 = r1 + 1; r2 <= N; r2++)
                for(int c2 = c1 + 1; c2 <= M; c2++){
                    int sum = right[r1][c2] - right[r1][c1 - 1] + left[r2][c1] - left[r2][c2 - 1]
                              + btm[r2][c2] - btm[r1][c2] + top[r1][c1] - top[r2][c1];
                    if(absx(T - sum) < absx(T - ans)){
                        ans = sum;
                        ansr1 = r1, ansr2 = r2, ansc1 = c1, ansc2 = c2;
                    }
                }

    printf("%d %d %d %d\n", ansr1, ansc1, ansr2, ansc2);
}
