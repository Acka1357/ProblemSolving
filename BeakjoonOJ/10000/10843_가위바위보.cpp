//
// Created by Acka on 2016. 12. 22..
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct RPS{
    int idx, cnt;
    bool operator <(const RPS &A)const{
        return cnt < A.cnt;
    }
};

int main()
{
    srand(time(NULL));

    int N; scanf("%d", &N);

    RPS rps[3];
    for(int i = 0; i < 3; i++)
        rps[i].idx = i;

    for(int i = 0, x; i < N; i++){
        scanf("%*d %d", &x);
        rps[x].cnt++;
    }

    int my = rand() % 3;
    if(3 < N){
        if(N / 2 < rps[2].cnt) my = (rps[2].idx + 1) % 3;
        else my = (rps[0].idx + 1) % 3;
    }

    printf("%d\n", my);
    return 0;
}

