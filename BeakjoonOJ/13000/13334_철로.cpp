//
// Created by Acka on 2017. 1. 19..
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct Line{
    int l, r;
    Line(){} Line(int l, int r):l(l), r(r){}
    bool operator <(const Line &A)const{
        return r < A.r;
    }
};

Line line[100000];

int main()
{
    int N, D; scanf("%d", &N);

    for(int i = 0, l, r; i < N; i++) {
        scanf("%d %d", &l, &r);
        line[i] = Line(min(l, r), max(l, r));
    }

    scanf("%d", &D);
    sort(line, line + N);

    int ans = 0, lm;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < N; i++){
        if(D < line[i].r - line[i].l) continue;

        q.push(line[i].l);
        lm = line[i].r - D;
        while(!q.empty()){
            if(q.top() < lm) q.pop();
            else break;
        }

        ans = max(ans, (int)q.size());
    }

    printf("%d\n", ans);
    return 0;
}

