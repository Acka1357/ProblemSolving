//
// Created by Acka on 2017. 2. 14..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
    Point(){} Point(int x, int y):x(x), y(y){}
};

int ccw(Point a, Point b, Point c){
    int ret = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
    return ret < 0 ? -1 : (ret ? 1 : 0);
}

struct Line{
    Point a, b;
    int minx, miny, maxx, maxy;
    Line(){}
    Line(Point a, Point b):a(a), b(b), minx(min(a.x, b.x)), maxx(max(a.x, b.x)), miny(min(a.y, b.y)), maxy(max(a.y, b.y)){}
    bool is_cross(Line &o){
        if(o.maxx < minx || maxx < o.minx) return false;
        if(o.maxy < miny || maxy < o.miny) return false;
        if(0 < ccw(a, b, o.a) * ccw(a, b, o.b) ||
                0 < ccw(o.a, o.b, a) * ccw(o.a, o.b, b)) return false;
        return true;
    }
};

Line seg, rec[4];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        seg = Line(Point(x1, y1), Point(x2, y2));

        int minx, maxy, maxx, miny; scanf("%d %d %d %d", &minx, &maxy, &maxx, &miny);
        if(maxx < minx){
            swap(minx, maxx);
            swap(miny, maxy);
        }

        rec[0] = Line(Point(minx, maxy), Point(minx, miny));
        rec[1] = Line(Point(maxx, maxy), Point(maxx, miny));
        rec[2] = Line(Point(minx, miny), Point(maxx, miny));
        rec[3] = Line(Point(minx, maxy), Point(maxx, maxy));

        bool ans = (minx <= seg.minx && seg.maxx <= maxx) && (miny <= seg.miny && seg.maxy <= maxy);
        for(int i = 0; i < 4; i++)
            ans |= rec[i].is_cross(seg);

        printf("%c\n", ans ? 'T' : 'F');
    }
    return 0;
}
