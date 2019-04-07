//
// Created by Acka on 2017. 8. 13..
//

#include <stdio.h>

char s[500][51], ns[500][51];
int chk1[4][4][4], chk2[4][4][4], trans[256];

int main()
{
    trans['A'] = 0; trans['C'] = 1; trans['G'] = 2; trans['T'] = 3;

    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);
    for(int i = 0; i < N; i++)
        scanf("%s", ns[i]);

    int ans = 0, chki = 1;
    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            for(int k = j + 1; k < M; k++){
                for(int ii = 0; ii < N; ii++)
                    chk1[trans[s[ii][i]]][trans[s[ii][j]]][trans[s[ii][k]]]
                            = chk2[trans[ns[ii][i]]][trans[ns[ii][j]]][trans[ns[ii][k]]] = chki;
                bool psb = true;
                for(int ii = 0; ii < 4; ii++)
                    for(int jj = 0; jj < 4; jj++)
                        for(int kk = 0; kk < 4; kk++)
                            if(chk1[ii][jj][kk] == chki && chk2[ii][jj][kk] == chki)
                                psb = false;
                if(psb) ans++;
                chki++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
