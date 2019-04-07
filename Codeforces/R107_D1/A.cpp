//
// Created by Acka on 2017. 4. 3..
//

#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    long long Q; scanf("%lld", &Q);

    vector<long long> ans;
    long long temp = Q;
    for(long long i = 2; i <= Q && i * i <= Q; i++)
        while(!(Q % i)){
            ans.push_back(i);
            Q /= i;
        }

    if(1 < Q) ans.push_back(Q);
    if(ans.size() == 2) printf("%d\n", ans.size());
    else{
        printf("%d\n", 1);
        printf("%lld\n", ans.size() < 2 ? 0 : ans[0] * ans[1]);
    }

    return 0;
}
