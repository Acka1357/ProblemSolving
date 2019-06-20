//
// Created by Acka on 10/31/16.
//

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int r, c;
    Node(){} Node(int r, int c):r(r), c(c){}
};

int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int N, a[100][100];

bool is_psb(int low, int up){
    bool chk[100][100] = {true,};
    queue<Node> q; q.push(Node(0, 0));
    while(!q.empty()){
        int r = q.front().r, c = q.front().c; q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nc < 0 || N <= nr || N <= nc) continue;
            if(!chk[nr][nc] && low <= a[nr][nc] && a[nr][nc] <= up){
                if(nr == N - 1 && nc == N - 1) return true;
                chk[nr][nc] = true;
                q.push(Node(nr, nc));
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    int ans = 200, low = 0, up = max(a[0][0], a[N - 1][N - 1]), lm = min(a[0][0], a[N - 1][N - 1]);
    while(low <= up && low <= lm && up <= 200){
        if(is_psb(low, up)){
            ans = min(ans, up - low);
            low++;
        }
        else up++;
    }

    printf("%d\n", ans);
    return 0;
}
