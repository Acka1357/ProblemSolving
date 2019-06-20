//
// Created by Acka on 2017. 8. 23..
//

#include <stdio.h>

int d[1 << 25], fl, bl, MOD, MOD_b, MOD_i, ans;

int ext_gcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1; y = 0;
        return a;
    }
    int d = ext_gcd(b , a % b, y , x);
    y -= (a / b) * x;
    return d;
}

void make_front(int idx, int val){
    if(idx == fl){
        d[val]++;
        return ;
    }
    for(int i = 1; i <= 26; i++)
        make_front(idx + 1, ((val * 33) ^ i) & MOD_b);
}

void make_back(int idx, int val){
    if(idx == bl){
        ans += d[val];
        return ;
    }
    for(int i = 1; i <= 26; i++)
        make_back(idx + 1, ((val ^ i) * MOD_i) & MOD_b);
}

int main()
{
    int N, K, M; scanf("%d %d %d", &N, &K, &M);
    MOD = 1 << M;
    MOD_b = MOD - 1;

    int x, y; ext_gcd(33, MOD, x, y);
    MOD_i = (MOD + (x % MOD)) % MOD;

    fl = (N + 1) / 2; bl = N - fl;
    make_front(0, 0);
    make_back(0, K);

    printf("%d\n", ans);
    return 0;
}*/


#include <stdio.h>

시간복잡도: 26^(n/2) * 2

hvalue[0] = 0
1) hv[i+1] = (hv[i] * 33) ^ a[i+1]) % mod

a^b = c이면 a = b^c 이므로
-> (hv[i-1] * 33) % mod = (s[i] ^ a[i]) % mod
-> hv[i-1] = ((hv[i] ^ a[i]) / 33) % mod (?)

곱셈 역원 계산
2) -> hv[i-1] = ((hv[i] ^ a[i]) * inv) % mod

1)과 2)를 이용하여 반반씩 구한다.


/*
long long n, k;
int dp[1 << 25];
long long mod, ans, inv;

void front(int hv, int idx) {
    if (idx == 0) {
        dp[hv]++;
        return;
    }
    for (int i = 1; i <= 26; i++)
        front(((hv*33)^i)&mod, idx - 1);
}

void back(int hv, int idx) {
    if (idx == n/2) {
        ans += dp[hv];
        return;
    }

    for (int i = 1; i <= 26; i++)
        back(((hv^i)*inv)&mod, idx - 1);
}

int main() {
    scanf("%d %d %d", &n, &k, &mod);
    int m = mod-1;
    mod = (1 << mod);
    //x&(mod-1)== x%mod
    mod--;

    //곱셈 역원 계산
    long long b = 33;
    inv = 1;
    while(m--) {
        inv = (inv * b) & mod;
        b = (b * b) & mod;
    }

    front(0, n / 2);
    back(k, n);
    printf("%lld", ans);
    return 0;
}
*/
