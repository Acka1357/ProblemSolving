//
// Created by Acka on 5/6/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int main()
{
    int N; scanf("%d", &N);
    int m1 = 2 * (N / 7);
    int m2 = m1;
    if(N % 7 == 6) m1++;
    if(2 <= N % 7) m2 += 2;
    else if(N % 7) m2++;
    printf("%d %d\n", m1, m2);
    return 0;
}
