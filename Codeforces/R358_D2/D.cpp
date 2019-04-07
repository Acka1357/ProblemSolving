#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int d[1000][1000][11][2];

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);

    char a[1001], b[1001];
    scanf("%s %s", a, b);

    if(a[0] == b[0]) d[0][0][1][1] = 1;
    for(int i = 1; i < N; i++) {
        d[i][0][1][0] = max(d[i - 1][0][1][0], d[i - 1][0][1][1]);
        if(a[i] == b[0]) d[i][0][1][1] = 1;
    }
    for(int i = 1; i < M; i++){
        d[0][i][1][0] = max(d[0][i - 1][1][0], d[0][i - 1][1][1]);
        if(a[0] == b[i]) d[0][i][1][1] = 1;
    }

    for(int i = 1; i < N; i++)
        for(int j = 1; j < M; j++){
            for(int k = 1; k <= K; k++)
                d[i][j][k][0] = max(max(d[i - 1][j][k][0], d[i][j - 1][k][0]), max(d[i - 1][j][k][1], d[i][j - 1][k][1]));

            if(a[i] == b[j]){
                for(int k = 1; k <= K; k++)
                    d[i][j][k][1] = max(d[i - 1][j - 1][k][1], max(d[i - 1][j - 1][k - 1][1], d[i - 1][j - 1][k - 1][0])) + 1;
            }
        }

    printf("%d\n", max(d[N - 1][M - 1][K][0], d[N - 1][M - 1][K][1]));
    return 0;
}

