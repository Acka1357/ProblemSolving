/*
//
// Created by Acka on 2017. 1. 15..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

long long int d[301][301], p[301], acc[301];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/pie_progress.txt", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/A.txt", "w", stdout);

    // codes


    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int N, M; scanf("%d %d", &N, &M);

        memset(d, 0x3f, sizeof(d));
        d[0][0] = 0;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++)
                scanf("%lld", &p[j]);

            sort(p + 1, p + M + 1);

            for(int j = 1; j <= M; j++)
                acc[j] = acc[j - 1] + p[j];

            for(int j = i, jm = min(N, i * M); j <= jm; j++)
                for (int k = max(0, j - i * M), km = min(j - i + 1, M); k <= km; k++)
                    d[i][j] = min(d[i][j], d[i - 1][j - k] + acc[k] + k * k);
        }

        printf("Case #%d: %lld\n", tc, d[N][N]);
    }
    return 0;
}
*/
