//
// Created by Acka on 2017. 4. 15..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

char map[26][26];
int top[26], btm[26], left[26], right[26];

int main()
{
//    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/B-large.in", "r", stdin);
//    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/B.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        memset(top, 0xff, sizeof(top));
        memset(btm, 0xff, sizeof(btm));
        memset(left, 0xff, sizeof(left));
        memset(right, 0xff, sizeof(right));

        int R, C; scanf("%d %d", &R, &C);
        for(int i = 0; i < R; i++)
            scanf("%s", map[i]);

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if('A' <= map[i][j] && map[i][j] <= 'Z'){
                    top[map[i][j] - 'A'] = i;
                    btm[map[i][j] - 'A'] = i;
                    left[map[i][j] - 'A'] = j;
                    right[map[i][j] - 'A'] = j;
                }

        for(int i = 0; i < 26; i++){
            if(top[i] < 0) continue;
            int tt = 0, bb = R - 1, ll = 0, rr = C - 1;
            for(int j = 0; j < 26; j++){
                if(top[j] < 0 || i == j) continue;
                if((btm[j] <= top[i] && right[j] < left[i]))
                    ll = max(ll, right[j] + (right[j] != left[i]));
                else if(btm[j] < top[i] && right[j] <= left[i])
                    tt = max(tt, btm[j] + (btm[j] != top[i]));
                else if((btm[j] <= top[i] && right[i] < left[j]))
                    tt = max(tt, btm[j] + (btm[j] != top[i]));
                else if(btm[j] < top[i] && right[i] <= left[j])
                    rr = min(rr, left[j] - (right[i] != left[j]));
                else if((btm[i] <= top[j] && right[j] < left[i]))
                    bb = min(bb, top[j] - (top[j] != btm[i]));
                else if((btm[i] < top[j] && right[j] <= left[i])){
                    ll = max(ll, right[j] + (left[i] != right[j]));
                else if((btm[i] <= top[j] && right[i] < left[j]))
                    bb = min(bb, top[j] - (btm[i] != top[j]));
                else if(btm[i] < top[j] && right[i] <= left[j])
                    rr = min(rr, left[j] - (right[i] != left[j]));
            }

            top[i] = tt; btm[i] = bb; left[i] = ll; right[i] = rr;
            printf("%c: (%d, %d) ~ (%d, %d)\n", 'A' + i, top[i], left[i], btm[i], right[i]);
            for(int r = top[i]; r <= btm[i]; r++)
                for(int c = left[i]; c <= right[i]; c++)
                    map[r][c] = 'A' + i;
        }

        printf("Case #%d:\n", tc);
        for(int i = 0; i < R; i++)
            printf("%s\n", map[i]);
    }
    return 0;
}

