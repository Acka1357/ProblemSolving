#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    int a[100000];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sort(a, a + N);

    int ans = N + 1, need = 1;
    for(int i = 0; i < N; i++){
        if(need <= a[i]){
            need++;
        }
    }

    printf("%d\n", need);
    return 0;
}

