//
// Created by Acka on 7/13/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int get_count(int a, int b, int c){
    return a / 3 + (a % 3 != 0) + b / 3 + (b % 3 != 0) + c / 3 + (c % 3 != 0);
}

int main()
{
    int a[3]; scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);

    int ans = get_count(a[0], a[1], a[2]);
    for(int i = 0; i <= a[0]; i++)
        for(int j = i; j <= a[1]; j++)
            ans = min(ans, j + get_count(a[0] - i, a[1] - j, a[2] - j));

    printf("%d\n", ans);
    return 0;
}
