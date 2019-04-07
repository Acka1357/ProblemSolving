//
// Created by Acka on 2017. 8. 8..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Point{
    int idx, add;
    bool operator <(const Point &A)const{
        return add < A.add;
    }
};

Point mid[501];
int d[501][501], a[501][501];

int main()
{
    memset(d, 0xff, sizeof(d));

    int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &mid[i].add);
        mid[i].idx = i;
        d[i][i] = 0; a[i][i] = mid[i].add;
    }

    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        d[u][v] = d[v][u] = c;
        a[u][v] = a[v][u] = max(mid[u].add, mid[v].add);
    }

    sort(mid + 1, mid + N + 1);

    for(int m = 1, k, add; m <= N; m++){
        k = mid[m].idx; add = mid[m].add;
        for(int i = 1; i <= N; i++){
            if(d[i][k] < 0) continue;
            for(int j = 1; j <= N; j++){
                if(d[k][j] < 0) continue;
                if(d[i][j] < 0 || d[i][k] + d[k][j] + max(mid[m].add, max(a[i][k], a[k][j])) < d[i][j] + a[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    a[i][j] = max(mid[m].add, max(a[i][k], a[k][j]));
                }
            }
        }
    }

    int S, T;
    while(Q--){
        scanf("%d %d", &S, &T);
        printf("%d\n", d[S][T] + a[S][T]);
    }

    return 0;
}
