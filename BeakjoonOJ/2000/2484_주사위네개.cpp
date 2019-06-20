//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4], ans;
int base[5] = {0, 0, 1000, 10000, 50000};
int mult[5] = {0, 100, 100, 1000, 5000};

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        sort(a, a + 4);

        int sum = 0;
        for(int j = 4; j > 1; j--){
            int cnt = 0;
            for(int k = 0; k < 4 - j + 1; k++)
                if(a[k] == a[k + j - 1]){
                    cnt++;
                    sum += base[j] + a[k] * mult[j];
                    k += j - 1;
                }
            if(sum){
                if(cnt == 2)
                    sum += (a[0] + a[2]) * 400;
                break;
            }
        }
        ans = max(ans, sum ? sum : a[3] * 100);
    }

    printf("%d\n", ans);
    return 0;
}
