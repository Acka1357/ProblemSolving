//
// Created by Acka on 10/13/16.
//

#include <stdio.h>
#include <map>
using namespace std;

long long int bit[256];
char s[300001];

int main()
{
    long long int b = 1, maxb = 1ll << 51;
    for (int i = 'a'; i <= 'z'; i++, b <<= 1)
        bit[i] = b;
    for (int i = 'A'; i <= 'Z'; i++, b <<= 1)
        bit[i] = b;

    int L; scanf("%d %s", &L, s);

    long long int ans = 0, cur = bit[s[0]];
    map<long long int, int> mp;
    for (int i = 0; i < L; i++){
        mp[cur]++; cur ^= bit[s[i]];
        if (mp.find(cur) != mp.end()) ans += mp[cur];
        for (long long int j = 1; j <= maxb; j <<= 1)
            if (mp.find(cur ^ j) != mp.end())
                ans += mp[cur ^ j];
    }

    printf("%lld\n", ans);
    return 0;
}

