//
// Created by Acka on 7/8/16.
//

#include <stdio.h>
#include <string.h>

int main()
{
    int idx[256], past[5] = {4, 0, 1, 2, 3};
    idx['q'] = 0; idx['u'] = 1; idx['a'] = 2; idx['c'] = 3; idx['k'] = 4;

    char s[2501]; scanf("%s", s);

    int d[5], l = strlen(s);
    for(int i = 0; i < l; i++) {
        d[idx[s[i]]]++;
        if(d[past[idx[s[i]]]]) d[past[idx[s[i]]]]--;
        else if(s[i] != 'q'){
            d[0] = -1; break;
        }
    }

    printf("%d\n", (d[0] || d[1] || d[2] || d[3]) ? -1 : d[4]);
    return 0;
}
