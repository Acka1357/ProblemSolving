//
// Created by Acka on 2017. 4. 30..
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

#define END     1440
#define HALF    720

struct Act{
    int start, end;
    bool operator <(const Act &A)const{
        return start < A.start;
    }
};

Act a[101], b[101];
int d[2][END + 1][HALF + 1][2];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/B-large (1).in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/B-large.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int A, B; scanf("%d %d", &A, &B);
        for(int i = 0; i < A; i++)
            scanf("%d %d", &a[i].start, &a[i].end);
        for(int i = 0; i < B; i++)
            scanf("%d %d", &b[i].start, &b[i].end);

        sort(a, a + A);
        sort(b, b + B);
        a[A].start = a[A].end = b[B].start = b[B].end = END + 1;

        memset(d, 0xff, sizeof(d));

        int ai = 0, bi = 0, c00, c11, c01, c10;
        if(0 < a[ai].start) d[0][1][1][0] = 0;
        if(0 < b[bi].start) d[1][1][0][1] = 0;

        for(int st = 0; st < 2; st++) {
            ai = bi = 0;
            for (int cur = 2; cur <= END; cur++) {
                if (a[ai].end < cur) ai++;
                if (b[bi].end < cur) bi++;

                for (int sum = min(HALF, cur); 0 <= sum; sum--) {
                    // until cur, A do sum
                    c00 = c11 = c01 = c10 = END;
                    if (sum) {
                        if (0 <= d[st][cur - 1][sum - 1][0])
                            c00 = d[st][cur - 1][sum - 1][0];
                    }
                    if (sum) {
                        if (0 <= d[st][cur - 1][sum - 1][1])
                            c10 = d[st][cur - 1][sum - 1][1] + 1;
                    }
                    if (0 <= d[st][cur - 1][sum][0])
                        c01 = d[st][cur - 1][sum][0] + 1;
                    if (0 <= d[st][cur - 1][sum][1])
                        c11 = d[st][cur - 1][sum][1];

                    if (cur <= a[ai].start)
                        d[st][cur][sum][0] = min(c00, c10);
                    if (cur <= b[bi].start)
                        d[st][cur][sum][1] = min(c11, c01);
                }
            }
        }

        int ans = END;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                if(0 <= d[i][END][HALF][j])
                    ans = min(ans, d[i][END][HALF][j] + (i == j ? 0 : 1));

        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}

