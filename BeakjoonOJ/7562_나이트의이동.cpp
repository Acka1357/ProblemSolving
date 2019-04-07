//
// Created by Acka on 2017. 7. 28..
//

#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

struct Crd{
    int r, c;
    Crd(int r, int c):r(r), c(c){}
};

int step[300][300];
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main()
{
    int T; for(scanf("%d", &T); T--;){
        int L, sr, sc, er, ec; scanf("%d %d %d %d %d", &L, &sr, &sc, &er, &ec);
        memset(step, 0, L * sizeof(step[0]));

        queue<Crd> q;
        q.push(Crd(sr, sc));
        step[sr][sc] = 1;
        int r, c, nr, nc;
        while(!q.empty()){
            r = q.front().r, c = q.front().c; q.pop();
            if(r == er && c == ec) break;
            for(int i = 0; i < 8; i++){
                nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= L || nc >= L) continue;
                if(!step[nr][nc]){
                    step[nr][nc] = step[r][c] + 1;
                    q.push(Crd(nr, nc));
                }
            }
        }

        printf("%d\n", step[er][ec] - 1);
    }
    return 0;
}
