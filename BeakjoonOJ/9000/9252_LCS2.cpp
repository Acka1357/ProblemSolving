//
// Created by Acka on 4/18/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char a[1002], b[1002]; scanf("%s %s", a + 1, b + 1);

    int d[1001][1001] = {0,};
    int l1 = strlen(a + 1), l2 = strlen(b + 1);
    for(int i = 1; i <= l1; i++)
        for(int j = 1; j <= l2; j++)
            d[i][j] = max(max(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1] + (a[i] == b[j]));

    char ans[1001] = {0,};
    int idx = d[l1][l2], i1 = l1, i2 = l2;
    while(idx){
        if(a[i1] == b[i2]){
            ans[--idx] = a[i1];
            i1--; i2--;
        }
        else if(d[i1][i2 - 1] <= d[i1 - 1][i2]) i1--;
        else i2--;
    }

    printf("%d\n%s\n", d[l1][l2], ans);
    return 0;
}
