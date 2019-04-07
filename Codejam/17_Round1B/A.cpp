//
// Created by Acka on 2017. 4. 23..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Seg{
    double x, t, spd;
    Seg(){};
    Seg(double x, double t, double s):x(x), t(t), spd(s){};
    bool operator <(const Seg &A)const{
        return x == A.x ? A.t < t : x < A.x;
    }
};

int absX(int x){
    return x < 0 ? -x : x;
}

Seg seg[1000000];
int loc[1001], spd[1001];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1B/A-large.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1B/A-large.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int D, N; scanf("%d %d", &D, &N);

        for(int i = 0; i < N; i++)
            scanf("%d %d", &loc[i], &spd[i]);

        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = i; j < N; j++){
                if(spd[i] == spd[j]){
                   seg[cnt++] =  Seg(min(loc[i], loc[j]), 0, spd[i]);
                }
                else{
                    double t = ((double)absX(loc[j] - loc[i])) / absX((spd[i] - spd[j]));
                    double d = loc[i] + spd[i] *  t;
                    if(d < D){
                        seg[cnt++] = Seg(loc[i] + spd[i] * t, t, min(spd[i], spd[j]));
                    }
                }
            }

        sort(seg, seg + cnt);

        double ans = D * 10001.0;
        for(int i = 0; i < cnt; i++){
            if(seg[i].t < 1e-9){
                ans = min(ans, seg[i].spd * D / (double)(D - seg[i].x));
            }
            else {
                ans = min(ans, seg[i].x / seg[i].t);
            }
        }

        printf("Case #%d: %.10lf\n", tc, ans);
    }
    return 0;
}

