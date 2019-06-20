#include <stdio.h>

char map[101];
int len, ans, cur;

int flip(int dir, char x){
    if(dir == 1 || dir == -1) return x;
    return x == 'B' ? 'W' : 'B';
}

bool good(){
    bool bchk = false, wchk = false;
    for(int i = 0; i < len; i++){
        if(map[i] == 'B'){
            if(bchk && wchk) return false;
            bchk = true;
        }
        else if(bchk && map[i] == 'W')
            wchk = true;
    }
    return true;
}

void min_hop(int cnt, int pastd){
    if(good()){
        ans = cnt;
        return ;
    }
    if(ans <= cnt || cnt >= 9) return ;

    for(int dir = -2; dir <= 2; dir++)
        if(dir && pastd != -dir && cur + dir >= 0 && cur + dir < len){
            map[cur] = flip(dir, map[cur + dir]);
            cur += dir;
            map[cur] = 'F';
            min_hop(cnt + 1, dir);
            map[cur] = flip(dir, map[cur - dir]);
            cur -= dir;
            map[cur] = 'F';
        }
}

int main()
{
    for(int tc = 1; scanf("%s", map); tc++){
        if(map[0] == '-') break;

        for(len = 0; map[len]; len++)
            if(map[len] == 'F') cur = len;

        ans = 987654321;
        min_hop(0, 0);
        printf("%d. %d\n", tc, ans > 10 ? -1 : ans);
    }
    return 0;
}
