//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Crd{
    int x, y;
};

int get_dir(int ox, int oy, int x, int y){
    if(ox < x) return oy < y ? 1 : 4;
    else return oy < y ? 2 : 3;
}

int xs[200], ys[200];
Crd crd[100];

int main()
{
    int N, B; scanf("%d %d", &N, &B);
    for(int i = 0, j = 0; i < N; i++, j += 2){
        scanf("%d %d", &crd[i].x, &crd[i].y);
        xs[j] = crd[i].x - 1; xs[j + 1] = crd[i].x + 1;
        ys[j] = crd[i].y - 1; ys[j + 1] = crd[i].y + 1;
    }

    int ans = N;
    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < 2 * N; j++){
            int cnt[5] = {0,};
            for(int k = 0; k < N; k++)
                cnt[get_dir(xs[i], ys[j], crd[k].x, crd[k].y)]++;

            int m = max(max(cnt[1], cnt[2]), max(cnt[3], cnt[4]));
            ans = min(ans, m);
        }
    }

    printf("%d\n", ans);
    return 0;
}
