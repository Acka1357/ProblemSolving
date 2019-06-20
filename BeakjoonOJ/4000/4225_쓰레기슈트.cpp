//
// Created by Acka on 7/24/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define CCW(A, B, C)    ((A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x))

struct Crd{
    int x, y;
    Crd(){} Crd(int x, int y):x(x), y(y){}

    int get_dist_sq(const Crd &A){
        return (A.x - x) * (A.x - x) + (A.y - y) * (A.y - y);
    }

    bool operator <(const Crd &A){
        return y == A.y ? x < A.x : y < A.y;
    }
};

Crd p[100], p0;

bool cmp(Crd A, Crd B){
    return CCW(p0, A, B) == 0 ? (A.get_dist_sq(p0) < B.get_dist_sq(p0)) : CCW(p0, A, B) < 0;
}

int main()
{
    for(int tc = 0; ++tc;) {
        int N; scanf("%d", &N);
        if(!N) break;

        scanf("%d %d", &p[0].x, &p[0].y);
        for (int i = 1; i < N; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
            if (p[i] < p[0]) {
                Crd temp = p[0];
                p[0] = p[i];
                p[i] = temp;
            }
        }

        p0 = p[0];
        sort(p + 1, p + N, cmp);

        vector<Crd> hull(N);
        hull[0] = p[0];
        hull[1] = p[1];

        int top = 1;
        for (int i = 2; i < N;) {
            if (top < 1) hull[++top] = p[i++];
            else if (CCW(hull[top], hull[top - 1], p[i]) > 0) hull[++top] = p[i++];
            else top--;
        }
        hull.resize(++top);

        Crd A, B, C, D;
        double ans = -1;
        for(int i = 0; i < top; i++){
            A = hull[i]; B = hull[(i + 1) % top];
            for(int j = 0; j < top; j++){
                C = hull[j]; D = Crd(C.x + B.x - A.x, C.y + B.y - A.y);

                bool psb = true;
                for(int k = 0; k < top; k++)
                    if(0 < CCW(A, B, hull[k]) * (long long)CCW(C, D, hull[k])){
                        psb = false; break;
                    }

                if(psb){
                    Crd line(B.x - A.x, B.y - A.y);
                    int um = (C.x - A.x) * line.x + (C.y - A.y) * line.y;
                    double ud = (line.x * line.x + line.y * line.y);
                    double dx = A.x + (um * line.x) / ud - hull[j].x, dy = A.y + (um * line.y) / ud - hull[j].y;
                    if(ans < 0) ans = dx * dx + dy * dy;
                    else ans = min(ans, dx * dx + dy * dy);
                }
            }
        }

        printf("Case %d: %.2lf\n", tc, sqrt(ans) + 0.005);
    }
    return 0;
}

