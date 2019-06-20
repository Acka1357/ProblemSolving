#include <stdio.h>
#include <memory.h>
#include <assert.h>
int map[55][55];
int dp[55][55];
int chk[6000000];
int t;
const int BASE = 1000 * 50 * 51;
int sum(int a, int b, int c, int d) {
    return dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
}
int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &map[i][j]);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];


    int cnt1 = 0, cnt2 = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            t++;
            for (int i1 = 1; i1 <= i; i1++)
                for (int j1 = 1; j1 <= j; j1++) {
                    int summ = sum(i1, j1, i, j) + 1000 * 50 * 51;
                    assert(i1 <= i && j1 <= j);
                    chk[summ] = (chk[summ] >= t * 50 * 50) ? chk[summ]++ : t * 50 * 50+1;
                    if(t == 9){
                        printf("[%02d] (%d, %d) ~ (%d, %d): %d, %d, %d\n", t, i1, j1, i, j, chk[summ] - t * 50 * 50, chk[summ], t * 50 * 50);
                    }
                }
            for (int i2 = i + 1; i2 <= N; i2++)
                for (int j2 = j + 1; j2 <= N; j2++) {
                    int summ = sum(i + 1, j + 1, i2, j2) + 1000 * 50 * 51;
                    assert(i <= i2 && j <= j2);
                    if (chk[summ] >= t * 50 * 50){
                        printf("[%02d] (%d, %d) ~ (%d, %d): %d\n", t, i + 1, j + 1, i2, j2, chk[summ] - t * 50 * 50 );
                        ans += chk[summ] - t * 50 * 50 ;
                        cnt1 += chk[summ] - t * 50 * 50;
                    }
                }
            t++;
            for (int i1 = 1; i1 <= i; i1++)
                for (int j2 = j + 1; j2 <= N; j2++) {
                    int summ = sum(i1, j + 1, i, j2) + 1000 * 50 * 51;
                    assert(i1 <= i && j <= j2);
                    chk[summ] = chk[summ] >= t * 50 * 50 ? chk[summ]++ : t * 50 * 50+1;
                }
            for (int i2 = i + 1; i2 <= N; i2++)
                for (int j1 = 1; j1 <= j; j1++) {
                    int summ = sum(i + 1, j1, i2, j) + 1000 * 50 * 51;
                    assert(i <= i2 && j1 <= j);
                    if (chk[summ] >= t * 50 * 50){
                        ans += chk[summ] - t * 50 * 50;
                        cnt2 += chk[summ] - t * 50 * 50;
                    }
                }
        }
    printf("%lld\n", ans);
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}
