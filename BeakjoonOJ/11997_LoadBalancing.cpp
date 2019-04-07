//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

struct Crd{
    int x, y;
};

Crd crd[1000];
int xs[1000], ys[1000];
int acc[1000][1000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &crd[i].x, &crd[i].y);
        xs[i] = crd[i].x; ys[i] = crd[i].y;
    }

    sort(xs, xs + N); sort(ys, ys + N);

    map<int, int> xmap, ymap;
    int xcnt = 0, ycnt = 0;
    xmap[xs[0]] = xcnt++; ymap[ys[0]] = ycnt++;
    for(int i = 1; i < N; i++)
        if(xs[i - 1] != xs[i]){
            xmap[xs[i]] = xcnt;
            xs[xcnt++] = xs[i];
        }
    for(int i = 1; i < N; i++)
        if(ys[i - 1] != ys[i]){
            ymap[ys[i]] = ycnt;
            ys[ycnt++] = ys[i];
        }

    for(int i = 0; i < N; i++)
        acc[xmap[crd[i].x]][ymap[crd[i].y]]++;

    for(int i = 0; i < xcnt; i++)
        for (int j = 0; j < ycnt; j++) {
            if (i && j) acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
            else if (i) acc[i][j] += acc[i - 1][j];
            else if (j) acc[i][j] += acc[i][j - 1];
        }

    int ans = N;
    for(int i = 0; i < xcnt; i++)
        for(int j = 0; j < ycnt; j++){
            int cnt1 = acc[i][j];
            int cnt2 = acc[i][ycnt - 1] - cnt1;
            int cnt3 = acc[xcnt - 1][j] - cnt1;
            int cnt4 = N - cnt1 - cnt2 - cnt3;
            int x = max(max(cnt1, cnt2), max(cnt3, cnt4));
            ans = min(ans ,x);
        }

    printf("%d\n", ans);
    return 0;
}
