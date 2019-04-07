//
// Created by Acka on 7/11/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

int N, all, d[16][1 << 16];
bool vic[16][16], maked[16][1 << 16];

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char s[17]; scanf("%s", s);
        for(int j = 0; j < N; j++)
            vic[i][j] = (s[j] == 'Y');
    }

    vector<int> bit[16][6];
    for(int i = 0, b = 1; i < N; i++, b <<= 1) {
        maked[i][b] = true;
        d[i][b] = 1;
        bit[i][0].push_back(b);
    }

    int nb;
    for(int k = 1, b = 1; b <= N; k++, b <<= 1)
        for(int v1 = 0; v1 < N; v1++)
            for(int v2 = 0; v2 < N; v2++){
                if(v1 == v2 || !vic[v1][v2]) continue;
                for(int i = 0; i < bit[v1][k - 1].size(); i++)
                    for(int j = 0; j < bit[v2][k - 1].size(); j++){
                        if(bit[v1][k - 1][i] & bit[v2][k - 1][j]) continue;
                        if(!maked[v1][nb = (bit[v1][k - 1][i] | bit[v2][k - 1][j])]){
                            bit[v1][k].push_back(nb);
                            maked[v1][nb] = true;
                        }
                        d[v1][nb] += 2 * d[v1][bit[v1][k - 1][i]] * d[v2][bit[v2][k - 1][j]];
                    }
            }

    all = (1 << N) - 1;
    for(int i = 0; i < N; i++)
        printf("%d ", d[i][all]);
    printf("\n");

    return 0;
}

