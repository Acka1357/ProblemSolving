//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[300000];
#define INF 10
int main()
{
    int N, arr[10][10];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++)

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    return 0;
}

