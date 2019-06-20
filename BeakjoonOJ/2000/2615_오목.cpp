//
// Created by Acka on 2017. 8. 25..
//

#include <stdio.h>

int map[19][19], ansr, ansc;
int sr[6] = {0, 18, 18, 18, 0, 1}, sc[6] = {18, 0, 18, 17, 0, 18};
int sdr[6] = {1, 0, -1, 0, 0, 1}, sdc[6] = {0, 1, 0, -1, 1, 0};
int dr[6] = {0, -1, -1, -1, 1, 1}, dc[6] = {-1, 0, -1, -1, -1, -1};

bool is_valid(int r, int c){
    return 0 <= r && r < 19 && 0 <= c && c < 19;
}

bool is_win(int x){
    for(int d = 0; d < 6; d++){
        int ssr = sr[d], ssc = sc[d];
        while(is_valid(ssr, ssc)){
            int cnt = 0, r = ssr, c = ssc;
            while(is_valid(r, c)){
                if(map[r][c] == x) cnt++;
                else{
                    if(cnt == 5){
                        ansr = r - dr[d], ansc = c - dc[d];
                        return true;
                    }
                    cnt = 0;
                }
                r += dr[d], c += dc[d];
            }
            if(cnt == 5){
                ansr = r - dr[d], ansc = c - dc[d];
                return true;
            }
            ssr += sdr[d], ssc += sdc[d];
        }
    }
    return false;
}

int main()
{
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            scanf("%d", &map[i][j]);

    if(is_win(1)) printf("%d\n%d %d\n", 1, ansr + 1, ansc + 1);
    else if(is_win(2)) printf("%d\n%d %d\n", 2, ansr + 1, ansc + 1);
    else printf("%d\n", 0);
    return 0;
}
