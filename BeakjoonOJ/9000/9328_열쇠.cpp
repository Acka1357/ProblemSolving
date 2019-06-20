//
// Created by Acka on 11/2/16.
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Crd{
    int r, c;
    Crd(){} Crd(int r, int c):r(r), c(c){}
};

char map[102][103];
int R, C, dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%d %d", &R, &C);
        for(int i = 1; i <= R; i++) {
            scanf("%s", map[i] + 1);
            map[i][0] = map[i][C + 1] = '.';
            map[i][C + 2] = '\0';
        }
        map[0][C + 2] = map[R + 1][C + 2] = '\0';
        for(int i = 0; i < C + 2; i++)
            map[0][i] = map[R + 1][i] = '.';

        bool has[26] = {false,}, chk[102][102] = {true,};
        char s[27]; scanf("%s", s);
        if(s[0] != '0'){
            for(int i = 0; s[i]; i++)
                has[s[i] - 'a'] = true;
        }

        int ans = 0;
        queue<Crd> q; q.push(Crd(0, 0));
        queue<Crd> wait[26];
        while(!q.empty()){
            int r = q.front().r, c = q.front().c; q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nc < 0 || R + 1 < nr || C + 1 < nc) continue;
                if(chk[nr][nc] || map[nr][nc] == '*') continue;
                chk[nr][nc] = true;
                if('A' <= map[nr][nc] && map[nr][nc] <= 'Z' && !has[map[nr][nc] - 'A']){
                    wait[map[nr][nc] - 'A'].push(Crd(nr, nc));
                    continue;
                }
                if('a' <= map[nr][nc] && map[nr][nc] <= 'z' && !has[map[nr][nc] - 'a']){
                    has[map[nr][nc] - 'a'] = true;
                    while(!wait[map[nr][nc] - 'a'].empty()){
                        q.push(wait[map[nr][nc] - 'a'].front());
                        wait[map[nr][nc] - 'a'].pop();
                    }
                }
                if(map[nr][nc] == '$') ans++;

                q.push(Crd(nr, nc));
            }

        }
        printf("%d\n", ans);
    }
    return 0;
}
