//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int main()
{
    int N, n; scanf("%d", &N);

    int y = 0, m = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        y += ((n / 30) + (n != 0)) * 10;
        m += ((n / 60) + (n != 0)) * 15;
    }

    int ans = y < m ? y : m;
    printf("%s%s%s %d\n", ans == y ? "Y" : "", y == m ? " " : "", ans == m ? "M" : "", ans);
    return 0;
}
