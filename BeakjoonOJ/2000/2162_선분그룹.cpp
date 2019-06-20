//
// Created by Acka on 2017. 2. 13..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
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
        int cross1 = ccw(a, b, o.a) * ccw(a, b, o.b);
        int cross2 = ccw(o.a, o.b, a) * ccw(o.a, o.b, b);
        if(0 < cross1 || 0 < cross2) return false;
        return true;
    }
};

Line line[3000];
vector<int> adj[3000];
bool chk[3000];

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0, x1, y1, x2, y2; i < N; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        line[i] = Line(Point(x1, y1), Point(x2, y2));
    }

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if (line[i].is_cross(line[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    int ans = 1, gcnt = 0;
    queue<int> q;
    for(int i = 0; i < N; i++)
        if(!chk[i]){
            int cnt = 0, cur; chk[i] = true;
            for(q.push(i); !q.empty(); q.pop()){
                cur = q.front(); cnt++;
                for(int j = 0; j < adj[cur].size(); j++)
                    if(!chk[adj[cur][j]]){
                        q.push(adj[cur][j]);
                        chk[adj[cur][j]] = true;
                    }
            }
            ans = max(ans, cnt);
            gcnt++;
        }

    printf("%d\n%d\n", gcnt, ans);
    return 0;
}
