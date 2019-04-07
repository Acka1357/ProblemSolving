//
// Created by Acka on 2017. 8. 23..
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN     100

char s[MAXN];
int gcnt[MAXN], nth[MAXN], pnth[MAXN];
vector<int> order, porder;

void sort_suffix(){
    int len = strlen(s), gn = 26, idx, i;
    order = vector<int>(len + 1, 0);
    porder = vector<int>(len + 1, 0);
    for(i = 0; i < len; i++)
        gcnt[order[i] = (s[i] - 'a' + 1)]++;
    for(i = 1; i <= gn; i++)
        gcnt[i] += gcnt[i - 1];
    for(i = len - 1; i >= 0; i--)
        nth[--gcnt[i]] = i;
    for(int p = 1; p < len; p <<= 1){
        for(idx = 0, i = len - p; i < len; i++)
            porder[++idx] = i;
        for(i = 0; i < len; i++)
            if(nth[i] >= len) porder[idx++] = nth[i] - len;
        memset(gcnt + 1, 0, gn * sizeof(gcnt[0]));
        for(i = 0; i < len; i++)
            gcnt[order[porder[i]]]++;
        for(i = 1; i <= gn; i++)
            gcnt[i] += gcnt[i - 1];
        for(i = len; i >= 0; i--)
            nth[gcnt[--order[porder[i]]]] = porder[i];
        swap(order, porder);
        idx = 1; order[nth[0]] = 0;
        for(i = 1; i < len; i++)


    }
}
