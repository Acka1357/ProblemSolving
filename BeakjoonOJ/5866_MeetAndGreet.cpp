//
// Created by Acka on 10/18/16.
//

#include <stdio.h>

int crd[2000001][2], c;

void set_crd(int N, int k){
    int x = 0, sumt = 1, t, d;
    while(N--){
        scanf("%d %c", &t, &c);
        d = (c == 'R' ? 1 : -1);
        t <<= 1;
        while(t--) crd[sumt++][k] = (x = (x + d));
    }
    while(sumt <= 2000000) crd[sumt++][k] = x;
}

int main()
{
    int B, E; scanf("%d %d", &B, &E);
    set_crd(B, 0);
    set_crd(E, 1);

    int ans = 0;
    for(int i = 1; i <= 2000000; i++)
        if (crd[i - 1][0] != crd[i - 1][1] && crd[i][0] == crd[i][1])
            ans++;

    printf("%d\n", ans);
    return 0;
}
