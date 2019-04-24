// solution:
// oa: a에 있는 값을 소팅.
// d[i][j][0]: a[i]를 oa[j]로 매칭시켰고, 증가단조수열일때 최소 합
// d[i][j][1]: a[i]를 oa[j]로 매칭시켰고, 감소단조수열일때 최소 합
// 실제 a에 들어있는 밸류 외에 다른 값과 매칭 시키는 것은 의미가 없음.

// 시간복잡도: O(N^2)
// 분류: DP
// 난이도: 1750   

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll absx(ll x){
    return x < 0 ? -x : x;
}

ll a[2002], d[2002][2002][2], oa[2002];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &a[i]);
        oa[i] = a[i];
    }

    sort(oa + 1, oa + N + 1);
    oa[N + 1] = 1000000000;

    memset(d, 0x3f, sizeof(d));
    d[0][0][0] = d[0][N + 1][1] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N + 1; j++){
            d[i][j][0] = d[i - 1][j][0] + absx(oa[j] - a[i]);
            if(j) d[i][j][0] = min(d[i][j][0], d[i][j - 1][0] - absx(oa[j - 1] - a[i]) + absx(oa[j] - a[i]));
        }
        for(int j = N + 1; j >= 0; j--){
            d[i][j][1] = d[i - 1][j][1] + absx(oa[j] - a[i]);
            if(j <= N) d[i][j][1] = min(d[i][j][1], d[i][j + 1][1] - absx(oa[j + 1] - a[i]) + absx(oa[j] - a[i]));
        }
    }

    ll ans = min(d[N][1][0], d[N][1][1]);
    for(int i = 2; i <= N; i++)
        ans = min({ans, d[N][i][0], d[N][i][1]});
    printf("%lld\n", ans);

    return 0;
}