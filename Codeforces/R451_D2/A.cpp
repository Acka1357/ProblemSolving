//
// Created by Acka on 2017. 12. 16..
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#include <memory.h>
using namespace std;

int main()
{
    int N; scanf("%d", &N);
    if(N % 10 != 0){
        if(N % 10 < 5) N -= (N % 10);
        else N += 10 - (N % 10);
    }
    printf("%d\n", N);
    return 0;
}

