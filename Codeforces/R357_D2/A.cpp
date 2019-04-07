#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    int a, b;
    bool ans = false;
    for(int i = 0; i < N; i++){
        scanf("%*s %d %d", &a, &b);
        if(2400 <= a && a < b) ans = true;
    }

    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}
