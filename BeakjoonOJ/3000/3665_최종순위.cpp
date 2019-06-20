#include <stdio.h>
#include <memory.h>

int org[501], nth[501], ans[501];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);
        for(int i = 1, x; i <= N; i++){
            scanf("%d", &x);
            org[x] = nth[x] = i;
        }

        int M; scanf("%d", &M);
        for(int i = 0, a, b; i < M; i++){
            scanf("%d %d", &a, &b);
            if(org[a] < org[b]) nth[a]++, nth[b]--;
            else nth[a]--, nth[b]++;
        }

        memset(ans + 1, 0, N * sizeof(ans[0]));
        bool psb = true;
        for(int i = 1; i <= N && psb; i++){
            if(ans[nth[i]]) psb = false;
            else ans[nth[i]] = i;
        }

        if(psb){
            for(int i = 1; i <= N; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
