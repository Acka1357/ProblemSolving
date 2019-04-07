//
// Created by Acka on 2016. 12. 9..
//

#include <stdio.h>

int N, K, mult[9];
char org[11][8][9];
unsigned long long int b[11], rmleft[8], rmright[8], rmtop[8], rmbtm[8];

unsigned long long int get_bit(char s[][9]){
    unsigned long long int ret = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            ret <<= 1;
            if(s[i][j] == '#') ret++;
        }
    return ret;
}

unsigned long long int shift_left(unsigned long long int x, int cnt){
    return (x << cnt) & rmright[cnt];
}

unsigned long long int shift_right(unsigned long long int x, int cnt){
    return (x >> cnt) & rmleft[cnt];
}

unsigned long long int shift_up(unsigned long long int x, int cnt){
    return (x << mult[cnt]) & rmbtm[cnt];
}

unsigned long long int shift_down(unsigned long long int x, int cnt){
    return (x >> mult[cnt]) & rmtop[cnt];
}

bool is_psb(int i1, int i2){
    unsigned long long int bit1, bit2;
    for(int x1 = 0; x1 < 2 * (N - 1); x1++)
        for(int y1 = 0; y1 < 2 * (N - 1); y1++) {
            bit1 = b[i1];
            if(x1 < N) bit1 = shift_left(bit1, x1);
            else bit1 = shift_right(bit1, x1 - N + 1);
            if(y1 < N) bit1 = shift_up(bit1, y1);
            else bit1 = shift_down(bit1, y1 - N + 1);

            if(bit1 & ~b[0]) continue;
            for (int x2 = 0; x2 < 2 * (N - 1); x2++)
                for (int y2 = 0; y2 < 2 * (N - 1); y2++) {
                    bit2 = b[i2];
                    if(x2 < N) bit2 = shift_left(bit2, x2);
                    else bit2 = shift_right(bit2, x2 - N + 1);
                    if(y2 < N) bit2 = shift_up(bit2, y2);
                    else bit2 = shift_down(bit2, y2 - N + 1);

                    if(bit1 & bit2) continue;
                    if((bit1 | bit2) == b[0]) return true;
                }
        }
    return false;
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i <= K; i++)
        for(int j = 0; j < N; j++)
            scanf("%s", org[i][j]);

    for(int i = 0; i <= N; i++)
        mult[i] = N * i;

    for(int i = 0; i <= K; i++)
        b[i] = get_bit(org[i]);

    char left[8][9], right[8][9], top[8][9], btm[8][9];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            left[i][j] = right[i][j] = top[i][j] = btm[i][j] = '#';

    rmleft[0] = rmright[0] = rmtop[0] = rmbtm[0] = get_bit(left);

    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++)
            left[j][i - 1] = right[j][N - i] = top[i - 1][j] = btm[N - i][j] = '.';
        rmleft[i] = get_bit(left);
        rmright[i] = get_bit(right);
        rmtop[i] = get_bit(top);
        rmbtm[i] = get_bit(btm);
    }

    for(int i = 1; i <= K; i++)
        for(int j = i + 1; j <= K; j++)
            if(is_psb(i, j)){
                printf("%d %d\n", i, j);
                break;
            }

    return 0;
}
