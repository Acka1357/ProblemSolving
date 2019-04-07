//
// Created by Acka on 6/1/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int tc; for(scanf("%d", &tc); tc--;) {
        long long int n; scanf("%lld", &n);

        vector<long long int> ans;
        for (long long int k = 1; k <= n && ans.empty(); k++) {
            if (n < (k * (k + 1)) / 2) break;
            if((2 * n) % (k + 1)) continue;

            long long int l = 1, r = n, a, sum;
            while(l <= r){
                a = (l + r) / 2;
                sum = ((k + 1) * (2 * a + k)) / 2;
                if(sum < n) l = a + 1;
                else if(n < sum) r = a - 1;
                else{
                    for(int i = 0; i <= k; i++)
                        ans.push_back(a + i);
                    break;
                }
            }
        }

        if (ans.empty()) printf("IMPOSSIBLE\n");
        else{
            printf("%lld = %lld", n, ans[0]);
            for(int i = 1; i < ans.size(); i++)
                printf(" + %lld", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
