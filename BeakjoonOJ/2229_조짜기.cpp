//
// Created by Acka on 2017. 5. 4..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int x[1001], d[1001];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &x[i]);

    for(int i = 1, minx, maxx; i <= N; i++){
        minx = maxx = x[i];
        for(int j = i - 1; j >= 0; j--){
            d[i] = max(d[i], d[j] + maxx - minx);
            maxx = max(maxx, x[j]);
            minx = min(minx, x[j]);
        }
    }

    printf("%d\n", d[N]);
    return 0;
}
