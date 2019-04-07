//
// Created by Acka on 2017. 4. 30..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

double p[50], rem;

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/C-small-1-attempt1.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1C/C.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N; scanf("%d %*d %lf", &N, &rem);
        for(int i = 0; i < N; i++)
            scanf("%lf", &p[i]);

        sort(p, p + N);

        double l = p[0], r = 1.0, m;
        for(int i = 0; i < 1000; i++){
            m = (l + r) / 2;

            double sum = 0;
            for(int j = 0; j < N; j++)
                if(p[j] < m) sum += m - p[j];

            if(rem < sum) r = m - eps;
            else l = m + eps;
        }

        double ans = 1;
        for(int i = 0; i < N; i++){
            if(p[i] < m) p[i] = m;
            ans *= p[i];
        }
        printf("Case #%d: %.9lf\n", tc, ans);
    }
    return 0;
}

