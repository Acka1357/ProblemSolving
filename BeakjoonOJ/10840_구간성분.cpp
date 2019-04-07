//
// Created by Acka on 4/18/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define DG  1511

vector<int> v[3][3000047];

bool search(int i, int h, int x){
    int l = 0, r = v[i][h].size() - 1, m;
    while(l <= r){
        m = (l + r) / 2;
        if(v[i][h][m] < x) l = m + 1;
        else if(x < v[i][h][m]) r = m - 1;
        else return true;
    }
    return false;
}

int main()
{
    long long int p[3] = {3000017, 3000047}, m[2][26];

    m[0][0] = m[1][0] = 1;
    for(int i = 1; i < 26; i++){
        m[0][i] = (m[0][i - 1] * DG) % p[0];
        m[1][i] = (m[1][i - 1] * DG) % p[1];
    }

    char a[1501], b[1501]; scanf("%s %s", a, b);

    int l1 = strlen(a), l2 = strlen(b), ans = 0;
    for(int i = 0; i < l1; i++){
        int idx[2] = {0,};
        for(int j = i; j < l1; j++)
            for(int k = 0; k < 2; k++){
                idx[k] = (idx[k] + m[k][a[j] - 'a']) % p[k];
                v[k][idx[k]].push_back(j - i + 1);
            }
    }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < p[i]; j++)
            sort(v[i][j].begin(), v[i][j].end());

    for(int i = 0; i < l2; i++){
        int idx[2] = {0,};
        for(int j = i; j < l2; j++){
            for(int k = 0; k < 2; k++)
                idx[k] = (idx[k] + m[k][b[j] - 'a']) % p[k];

            if(ans <= j - i){
                if(search(0, idx[0], j - i + 1) && search(1, idx[1], j - i + 1))
                    ans = j - i + 1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
