#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    long long int N, M;
    scanf("%lld %lld", &N, &M);

    long long int ans = 0;
    for(int i = 0; i < 5; i++){
        int j = i ? 5 - i : 0;
        ans += (N / 5 + (i ? (i <= N % 5) : 0)) * (M / 5 + (j ? (j <= M % 5) : 0));
    }

    printf("%lld\n", ans);
    return 0;
}

