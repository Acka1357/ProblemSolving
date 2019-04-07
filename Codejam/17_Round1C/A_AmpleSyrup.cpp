//
// Created by Acka on 2017. 4. 30..
//

#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const double PI = acos(-1.0);

struct Cake{
    int r, h;
    bool operator <(const Cake &A)const{
        return r > A.r;
    }
};

Cake cake[1000];
double d[1000][1001];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/A-large-practice.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/A-large-practice.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N, K; scanf("%d %d", &N, &K);

        for(int i = 0; i < N; i++)
            scanf("%d %d", &cake[i].r, &cake[i].h);

        sort(cake, cake + N);

        d[0][1] = PI * cake[0].r * cake[0].r + 2 * PI * cake[0].r * cake[0].h;
        for(int i = 1; i < N; i++) {
            d[i][1] = max(d[i - 1][1], PI * cake[i].r * cake[i].r + 2 * PI * cake[i].r * cake[i].h);
            for(int k = min(i + 1, K); 1 < k; k--)
                d[i][k] = max(d[i - 1][k], d[i - 1][k - 1] + 2 * PI * cake[i].r * cake[i].h);
        }

        printf("Case #%d: %.9lf\n", tc, (double)d[N - 1][K]);
    }
    return 0;
}

