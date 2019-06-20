#include <cstdio>
#include <cstring>

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge{
    int from, to; ll cost;
};

ll mind[501];
Edge e[6001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
        scanf("%d %d %lld", &e[i].from, &e[i].to, &e[i].cost);

    memset(mind, 0x3f, sizeof(mind));
    for(int step = mind[1] = 0; step <= N; step++)
        for(int i = 0; i < M; i++)
            if(mind[e[i].from] < INF && mind[e[i].to] > mind[e[i].from] + e[i].cost){
                mind[e[i].to] = mind[e[i].from] + e[i].cost;
                if(step == N) return printf("-1\n") & 0;
            }

    for(int i = 2; i <= N; i++)
        printf("%lld\n", mind[i] < INF ? mind[i] : -1);

    return 0;
}
