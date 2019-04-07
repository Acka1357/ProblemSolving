/*
//
// Created by Acka on 2017. 1. 8..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Qualification/lazy_loading.txt", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Qualification/B.txt", "w", stdout);

    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int N; scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        sort(a, a + N);

        int ans;
        for(ans = N; 1 <= ans; ans--){
            int rem = N - ans;
            for(int j = N - ans; j < N && 0 <= rem; j++)
                rem -= 49 / a[j];

            if(0 <= rem) break;
        }

        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
*/
