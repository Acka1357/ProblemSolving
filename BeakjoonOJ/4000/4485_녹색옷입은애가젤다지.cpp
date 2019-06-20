//
// Created by Acka on 2017. 12. 9..
//

#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

struct Stat{
    int r, c, sum;
    Stat(int r, int c, int s):r(r), c(c), sum(s){}
    bool operator <(const Stat &o)const{
        return sum > o.sum;
    }
};

int N, tc, map[125][125], mins[125][125];
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

int main()
{
    for(tc = 1; scanf("%d", &N); tc++){
        if(!N) break;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &map[i][j]);

        memset(mins, 0x3f, sizeof(mins));
        priority_queue<Stat> q;
        q.push(Stat(0, 0, mins[0][0] = map[0][0]));
        while(!q.empty()){
            int r = q.top().r, c = q.top().c, sum = q.top().sum; q.pop();
            if(mins[r][c] < sum) continue;
            if(r == N - 1 && c == N - 1){
                printf("Problem %d: %d\n", tc, sum);
                break;
            }

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nc < 0|| nr >= N || nc >= N) continue;
                if(mins[nr][nc] > sum + map[nr][nc])
                    q.push(Stat(nr, nc, mins[nr][nc] = sum + map[nr][nc]));
            }
        }
    }
    return 0;
}
