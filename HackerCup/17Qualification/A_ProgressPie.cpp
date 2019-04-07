/*
//
// Created by Acka on 2017. 1. 8..
//

#include <stdio.h>
#include <math.h>

double ccw(double x1, double y1, double x2, double y2, double x3, double y3){
    return x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
}

int main()
{
    const double PI = acos(-1.0);

//    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Qualification/progress_pie.txt", "r", stdin);
//    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Qualification/A.txt", "w", stdout);

    int T; scanf("%d", &T);
    for(int tc = 1, R = 50; tc <= T; tc++){
        int P, X, Y; scanf("%d %d %d", &P, &X, &Y);
        X -= 50; Y -= 50;

        bool ans = false;
        if(R * R < X * X + Y * Y || !P);
        else if(P == 100) ans = true;
        else if(X == 0){
            if(0 <= Y) ans = true;
            else if(50 <= P) ans = true;
        }
        else{
            double a = (PI * P) / 50.0;
            double PX = sin(a) * 100, PY = cos(a) * 100;
            if(-(1e-13) <= ccw(0, 0, PX, PY, X, Y)) ans = true;
        }

        printf("Case #%d: %s\n", tc, ans ? "black" : "white");
    }
    return 0;
}
*/
