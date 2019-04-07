//
// Created by Acka on 5/3/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Work{
    int n, i;
    bool operator < (const Work &A)const{
        return n < A.n;
    }
};

int main()
{
    int N; scanf("%d", &N);

    Work n[100000];
    for(int i = 0; i < N; i++){
        scanf("%d", &n[i].n);
        n[i].i = i;
    }

    sort(n, n + N);

    long long int ans[100000], sum = 0;
    for(int i = 0; i < N; i++){
        ans[n[i].i] = (n[i].n - 1) * N + n[i].i + 1;
        sum += n[i].n;
    }

    for(int i = 0; i < N; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
