// solution:
// 각 정점의 아웃디그리가 1이므로 나올 수 있는 컴포넌트의 형태는
// 하나의 심플 사이클이거나, 심플 사이클로 들어오는 직선 경로들이 있는 형태.
// dfs 탐색을 하며 현재 탐색중인 노드에 다시 방문하게 된 경우
// 사이클 구간을 찾은 것이므로 해당 노드까지 리턴하면서 답에서 빼준다.

// 분류: Cycle
// 시간복잡도: O(V)
// 난이도: 1500

#include <cstdio>
#include <cstring>

int chk[100001], nxt[100001], ans;

int dfs(int cur){
    chk[cur] = 1;
    int ret = 0;
    if(chk[nxt[cur]] < 0);
    else if(chk[nxt[cur]] == 1)
        ret = nxt[cur];
    else ret = dfs(nxt[cur]);

    if(ret) ans--;
    chk[cur] = -1;
    return ret == cur ? 0 : ret;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);
        memset(chk, 0, (N + 1) * sizeof(chk[0]));
        for(int i = 1; i <= N; i++)
            scanf("%d", &nxt[i]);

        ans = N;
        for(int i = 1; i <= N; i++)
            if(!chk[i]) dfs(i);

        printf("%d\n", ans);
    }
    return 0;
}
