//
// Created by Acka on 7/4/16.
//


#include <stdio.h>

#define MOD 1000000007

int r[100001][2];
int root(int x) {
    if (r[r[x][0]][0] == r[x][0]) return r[x][0];

    int n = root(r[x][0]);
    r[x][1] ^= r[r[x][0]][1];
    r[x][0] = n;
    return n;
}
int main() {
    int N, M, i, t1, t2, t3;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        r[i][0] = i;
        r[i][1] = 0;
    }

    for (i = 1; i <= M; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        int x = root(t1);
        int y = root(t2);
        int z = (1 - t3) ^ r[t1][1] ^ r[t2][1];
        if (x == y) {
            if (z == 1) break;
            continue;
        }
        r[x][0] = y;
        r[x][1] = z;
    }

    if (i <= M) {
        printf("0");
        return 0;
    }
    int cnt = -1;
    for (i = 1; i <= N; i++) {
        if (i == r[i][0]) cnt++;
    }

    long long int ans = 1;
    for (i = 1; i <= cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }
    printf("%lld", ans);
    return 0;
}
