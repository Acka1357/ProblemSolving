//
// Created by Acka on 8/29/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

long long int map[500][500];

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%lld", &map[i][j]);

    if(N == 1){
        printf("1\n");
        return 0;
    }

    long long int all = 0;
    for(int i = 0; i < N; i++){
        bool psb = true;
        for(int j = 0; j < N; j++){
            if(map[i][j]) all += map[i][j];
            else{
                all = 0;
                psb = false; break;
            }
        }
        if(psb) break;
    }

    long long int x = -1;
    bool psb = true;
    for(int i = 0; i < N; i++){
        bool zero = false;
        long long int sum = 0;
        for(int j = 0; j < N; j++){
            if(map[i][j]) sum += map[i][j];
            else zero = true;
        }
        if(zero) x = all - sum;
        else if(sum != all){
            psb = false; break;
        }
    }

    if(x <= 0) psb = false;
    for(int i = 0; i < N && psb; i++){
        long long int sum = 0;
        for(int j = 0; j < N; j++){
            if(map[j][i]) sum += map[j][i];
            else sum += x;
        }
        if(sum != all) psb = false;
    }

    long long int sum = 0;
    for(int i = 0, j = 0; i < N && psb; i++, j++){
        if(map[i][j]) sum += map[i][j];
        else sum += x;
    }
    if(sum != all) psb = false;

    sum = 0;
    for(int i = 0, j = N - 1; i < N && psb; i++, j--){
        if(map[i][j]) sum += map[i][j];
        else sum += x;
    }
    if(sum != all) psb = false;

    if(!psb) x = -1;
    printf("%lld\n", x);
    return 0;
}

