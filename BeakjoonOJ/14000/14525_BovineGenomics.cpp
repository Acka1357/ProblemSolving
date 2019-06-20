//
// Created by Acka on 2017. 8. 13..
//

#include <stdio.h>

bool same[500][500];
char s[500][501], ns[500][501];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);
    for(int i = 0; i < N; i++)
        scanf("%s", ns[i]);


    return 0;
}
