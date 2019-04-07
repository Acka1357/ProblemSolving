#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int c[3] = {1234567, 123456, 1234};
    int N; scanf("%d", &N);

    bool ans = false;
    for(int i = N / c[0]; 0 <= i && !ans; i--)
        for(int j = (N - i * c[0]) / c[1]; 0 <= j; j--)
            if(!((N - i * c[0] - j * c[1]) % c[2])){
                ans = true;
                break;
            }

    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}

