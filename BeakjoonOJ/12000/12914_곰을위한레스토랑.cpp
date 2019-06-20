//
// Created by Acka on 7/7/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, D; scanf("%d %d", &N, &D);

    int w[1000];
    for(int i = 0; i < N; i++)
        scanf("%d", &w[i]);

    printf("%d ", w[0]);
    int d[1000] = {w[0]};
    for(int i = 1; i < N; i++){
        sort(d, d + i);

        if(w[i] + D <= d[0]){
            printf("%d ", d[i] = w[i]);
            continue;
        }

        for(int j = 1; j < i; j++){
            if(d[j - 1] + D <= w[i] && w[i] <= d[j] - D){
                printf("%d ", d[i] = w[i]);
                break;
            }
            if(d[j] - d[j - 1] < 2 * D || d[j - 1] + D < w[i]) continue;
            printf("%d ", d[i] = (d[j - 1] + D));
            break;
        }
        if(!d[i]) printf("%d ", d[i] = max(w[i], d[i - 1] + D));
    }

    printf("\n");
    return 0;
}
