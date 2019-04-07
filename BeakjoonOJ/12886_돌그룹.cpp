//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[1501][1501];
int sum, x;

int set_d(int a, int b){
    if(a == x && b == x) return d[x][x] = 1;
    int c = sum - a - b;

    int n[3] = {a, b, c};
    sort(n, n + 3);

    if(0 <= d[n[0]][n[1]]) return d[n[0]][n[1]];
    d[n[0]][n[1]] = 0; if(!n[0]) return 0;

    if(set_d(2 * n[0], n[1] - n[0]) == 1) return 1;
    if(set_d(2 * n[0], n[1]) == 1) return 1;
    if(set_d(n[0], 2 * n[1]) == 1) return 1;
    return 0;
}

int main()
{
    int n[3]; scanf("%d %d %d", &n[0], &n[1], &n[2]);
    if((sum = (n[0] + n[1] + n[2])) % 3){
        printf("0\n"); return 0;
    }

    x = sum / 3;
    sort(n, n + 3);

    memset(d, 0xff, sizeof(d));

    printf("%d\n", set_d(n[0], n[1]));
    return 0;
}
