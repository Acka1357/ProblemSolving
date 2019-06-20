//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int cur[1000];
queue<int> pool[1000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, c; i < N; i++) {
        scanf("%d", &c);
        while(c--) pool[i].push(0);
    }

    int ans = 0;
    for(int t = 0; t < N; t++){
        bool chk = false;
        for(int i = 0; i < N; i++)
            if(1 < pool[i].size()){
                while(1 < pool[i].size()){
                    pool[(i + 1) % N].push(pool[i].front() + 1);
                    pool[i].pop();
                    chk = true;
                }
            }
        if(!chk) break;
    }

    for(int i = 0; i < N; i++)
        ans += pool[i].front() * pool[i].front();

    printf("%d\n", ans);
    return 0;
}
