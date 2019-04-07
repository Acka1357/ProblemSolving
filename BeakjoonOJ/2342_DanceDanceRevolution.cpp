#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int d[100001][5][5];

int main()
{
    int cost[5][5] = {{ 0, 2, 2, 2, 2 },
                    { 0, 1, 3, 4, 3 },
                    { 0, 3, 1, 3, 4 },
                    { 0, 4, 3, 1, 3 },
                    { 0, 3, 4, 3, 1 }};

    memset(d, 0x3f, sizeof(d));

    int N = 0;
    for(int i = 1; i < 5; i++)
        d[N][i][0] = d[N][0][i] = cost[0][i];

    int next, past; scanf("%d", &past);
    if(!past) return printf("0\n") & 0;

    while (scanf("%d", &next) == 1){
        if (!next) break;

        N++;
        for(int i = 0; i < 5; i++){
            if(next != i && past != i){
                d[N][next][i] = min(d[N][next][i], d[N - 1][past][i] + cost[past][next]);
                d[N][i][next] = min(d[N][i][next], d[N - 1][i][past] + cost[past][next]);
            }
            if(past != next && past != i) {
                d[N][past][next] = min(d[N][past][next], d[N - 1][past][i] + cost[i][next]);
                d[N][next][past] = min(d[N][next][past], d[N - 1][i][past] + cost[i][next]);
            }
        }
        past = next;
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 5; i++)
        ans = min(ans, min(d[N][past][i], d[N][i][past]));

    printf("%d\n", ans);
    return 0;
}
