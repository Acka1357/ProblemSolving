//
// Created by Acka on 2017. 5. 18..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int n[20001];

int main()
{
    int N, sum = 0; scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &n[i]);
        sum += n[i];
    }

    sort(n + 1, n + N + 1);

    int ans = 0, dif = sum, ni = 0;
    for(int i = 1; i <= n[N]; i++){
        while(n[ni] < i) ni++;
        sum += ni - 1;
        sum -= N - ni + 1;
        if(sum < dif){
            dif = sum;
            ans = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}
