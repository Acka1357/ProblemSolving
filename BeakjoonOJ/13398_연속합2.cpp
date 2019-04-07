//
// Created by Acka on 2017. 4. 12..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001], d[100001][2];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    a[0] = d[0][0] = d[0][1] = -1001;
    int ans = d[0][0];
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 2; j++){
            if(d[i - 1][j] < 0) d[i][j] = a[i];
            else d[i][j] = d[i - 1][j] + a[i];
        }
        d[i][1] = max(d[i][1], d[i - 1][0]);
        ans = max(ans, max(d[i][0], d[i][1]));
    }

    printf("%d\n", ans);
    return 0;
}
