//
// Created by Acka on 2017. 8. 11..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Run{
    int part, nth, t;
    bool operator <(const Run &A)const{
        return t < A.t;
    }
};

Run a[100000 * 2];
char ans[2][100001];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, idx = 0; i < N; i++, idx += 2){
        if(i < N / 2) ans[0][i] = ans[1][i] = '1';
        else ans[0][i] = ans[1][i] = '0';
        scanf("%d %d", &a[idx].t, &a[idx + 1].t);
        a[idx].part = 0, a[idx].nth = i;
        a[idx + 1].part = 1, a[idx + 1].nth = i;
    }

    sort(a, a + 2 * N);
    for(int i = 0; i < N; i++)
        ans[a[i].part][a[i].nth] = '1';

    printf("%s\n%s\n", ans[0], ans[1]);
    return 0;
}
