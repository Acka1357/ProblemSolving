//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int absx(int x){
    return x < 0? -x : x;
}

bool d[2][101][101];

int main()
{
    int X, Y, K, M; scanf("%d %d %d %d", &X, &Y, &K, &M);

    int ans = M, t = 0;
    d[t][0][0] = true;
    for(int k = 0; k < K; k++, t = !t)
        for(int i = 0; i <= X; i++)
            for(int j = 0; j <= Y; j++)
                if(d[t][i][j]){
                    d[!t][i][0] = d[!t][0][j] = d[!t][X][j] = d[!t][i][Y] = true;
                    if(X - i < j) d[!t][X][j - X + i] = true;
                    else d[!t][i + j][0] = true;
                    if(Y - j < i) d[!t][i - Y + j][Y] = true;
                    else d[!t][0][i + j] = true;
                }

    for(int i = 0; i <= X; i++)
        for(int j = 0; j <= Y; j++)
            if(d[t][i][j]) ans = min(ans, absx(M - i - j));

    printf("%d\n", ans);
    return 0;
}
