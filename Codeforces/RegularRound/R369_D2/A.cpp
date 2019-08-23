//
// Created by Acka on 8/29/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

int main()
{
    char map[1001][7];

    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    bool psb = false;
    for(int i = 0; i < N; i++){
        if(map[i][0] == map[i][1] && map[i][1] == 'O'){
            map[i][0] = map[i][1] = '+';
            psb = true; break;
        }
        else if(map[i][3] == map[i][4] && map[i][3] == 'O'){
            map[i][3] = map[i][4] = '+';
            psb = true; break;
        }
    }

    if(!psb){
        printf("%s\n", "NO");
        return 0;
    }

    printf("%s\n", "YES");
    for(int i = 0; i < N; i++)
        printf("%s\n", map[i]);

    return 0;
}
