//
// Created by Acka on 2017. 8. 13..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Info{
    int x, y;
    bool operator <(const Info &A)const{
        return y < A.y;
    }
};

Info info[100000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &info[i].x, &info[i].y);

    sort(info, info + N);

    int ans = 0, f = 0, t = N - 1;
    while(f <= t){
        ans = max(ans, info[f].y + info[t].y);
        if(--info[f].x == 0) f++;
        if(--info[t].x == 0) t--;
    }

    printf("%d\n", ans);
    return 0;
}
