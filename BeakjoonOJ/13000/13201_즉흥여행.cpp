// solution:
// 모든 경로 중 가장 높은 확률의 경로의 마지막 지점을 구하는 문제
// (각 지점 중 마지막이 될 확률이 가장 높은 걸 구하는게 아님)
// d[K][N]: k번째 여행이 n번 공항일 확률 중 최댓값
// 실수오차에 주의해야하는데, long double을 쓰면 해결되긴 한다. 다만 시간이 아슬아슬함.
// 확률곱의 대소비교가 필요할 때에는 각 확률을 log를 취하면 곱셈이 덧셈으로 변하면서
// double 로도 충분한 정밀도가 나온다.

// 시간복잡도: O(K * N^2)
// 분류: Probability DP
// 난이도: 1750 (오차때문에 좀 높임)

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int cnt[101][101];
char ia[101][4];
long double d[1001][101], p[101][101];

int main()
{   
    int tc; for(scanf("%d", &tc); tc--;) {
        int N, K, ii = 0; scanf("%d %d", &N, &K);
        for(int i = 1; i <= N; i++){
            scanf("%s", ia[i]);
            if(strcmp(ia[i], "ICN") == 0) ii = i;
        }
        for(int i = 1; i <= N; i++){
            int sum = 0;
            for(int j = 1; j <= N; j++){
                scanf("%d", &cnt[i][j]);
                sum += cnt[i][j];
            }
            for(int j = 1; j <= N; j++)
                p[i][j] = log((long double)cnt[i][j] / sum);
        }

        memset(d, 253, (K + 1) * sizeof(d[0]));
        d[0][ii] = 0;
        for(int i = 1; i <= K; i++)
            for(int j = 1; j <= N; j++) 
                for(int k = 1; k <= N; k++)
                    d[i][j] = max(d[i][j], d[i - 1][k] + p[k][j]);

        int imax = 1;
        long double pmax = d[K][1];
        for(int i = 2; i <= N; i++)
            if(pmax < d[K][i]){
                pmax = d[K][i];
                imax = i;
            }
        printf("%s\n", ia[imax]);
    }
    return 0;
}
