//
// Created by Acka on 7/3/16.
//

#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

#define ABS(x)					((x) < 0 ? -(x) : (x))
#define DIS_SQ(x1, y1, x2, y2)	((x1 - (x2)) * (x1 - (x2)) + (y1 - (y2)) * (y1 - (y2)))
#define MIN(a, b)				((a) < (b) ? (a) : (b))

bool inBound(double x1, double y1, double x2, double y2, double a, double b){
    bool ret = false;

    double inter_x, inter_y;
    if (x1 != x2){
        double m = (y1 - y2) / (x1 - x2);
        double k = y1 - ((y1 - y2) * x1) / (x1 - x2);

        inter_x = (m * b - m * k + a) / (m * m + 1);
        inter_y = (m * inter_x + k);
    }
    else{
        inter_x = x1; inter_y = b;
    }

    if ((inter_x - x1) * (inter_x - x2) <= 0 && ((inter_y - y1) * (inter_y - y2)) <= 0){
        double dis = DIS_SQ(a, b, inter_x, inter_y);
        if (DIS_SQ(a, b, inter_x, inter_y) < 3.999999) ret = true;
    }

    else{
        double d1 = DIS_SQ(x1, y1, a, b), d2 = DIS_SQ(x2, y2, a, b);
        if (MIN(d1, d2) < 3.999999) ret = true;
    }

    return ret;
}

int main()
{
    int pool[6][2] = { { 0, 0 }, { 54, 0 }, { 108, 0 }, { 0, 54 }, { 54, 54 }, { 108, 54 } };

    double wx, wy, bx, by, other[16][2];
    while (scanf("%lf", &wx) == 1){
        if(wx <= 0.00000000001) break;

        scanf("%lf %lf %lf", &wy, &bx, &by);

        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &other[i][0], &other[i][1]);
        other[n][0] = bx; other[n][1] = by;

        queue<int> q;
        for (int i = 0; i < 6; i++){
            bool pos = true;

            for (int j = 0; j < n && pos; j++){
                if (inBound(bx, by, pool[i][0], pool[i][1], other[j][0], other[j][1]))
                    pos = false;
            }

            if (!pos) continue;

            double dx = 2 * sqrt((bx - pool[i][0]) * (bx - pool[i][0]) / DIS_SQ(bx, by, pool[i][0], pool[i][1]));
            double dy = (bx == pool[i][0]) ? 2 : ABS((dx * (by - pool[i][1])) / (bx - pool[i][0]));

            double new_x = bx + (pool[i][0] < bx ? dx : -dx);
            double new_y = by + (pool[i][1] < by ? dy : -dy);
            if (new_x < 0 || new_y < 0 || new_x > 108 || new_y > 54) continue;

            for (int j = 0; j <= n && pos; j++){
                if (inBound(wx, wy, new_x, new_y, other[j][0], other[j][1]))
                    pos = false;
            }

            if (pos) q.push(i + 1);
        }

        if (q.empty()) printf("no shot\n");
        else{
            int temp = q.front(); q.pop();
            while (!q.empty()){
                printf("%d ", temp);
                temp = q.front(); q.pop();
            }
            printf("%d\n", temp);
        }
    }
    return 0;
}
