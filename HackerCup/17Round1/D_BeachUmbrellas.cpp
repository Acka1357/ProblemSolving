/*
//
// Created by Acka on 2017. 1. 16..
//

#include <stdio.h>

#define MOD     1000000007

long long invert_mod(long long k, long long m)
{
    if (m == 0) return (k == 1 || k == -1) ? k : 0;
    if (m < 0) m = -m;
    k %= m;
    if (k < 0) k += m;
    int neg = 1;
    long long p1 = 1, p2 = 0, k1 = k, m1 = m, q, r, temp;
    while(k1 > 0) {
        q = m1 / k1;
        r = m1 % k1;
        temp = q*p1 + p2;
        p2 = p1;
        p1 = temp;
        m1 = k1;
        k1 = r;
        neg = !neg;
    }
    return neg ? m - p2 : p2;
}

// Preconditions: 0 <= k <= min(n,p-1); p > 1 prime
long long choose_mod_two(long long n, long long k, long long p)
{
    // reduce n modulo p
    n %= p;
    // Trivial checks
    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    // Now 0 < k < n, save a bit of work if k > n/2
    if (k > n/2) k = n-k;
    // calculate numerator and denominator modulo p
    long long num = n, den = 1;
    for(n = n-1; k > 1; --n, --k)
    {
        num = (num * n) % p;
        den = (den * k) % p;
    }
    // Invert denominator modulo p
    den = invert_mod(den,p);
    return (num * den) % p;
}

// Preconditions: 0 <= k <= n; p > 1 prime
long long choose_mod_one(long long n, long long k, long long p)
{
    // For small k, no recursion is necessary
    if (k < p) return choose_mod_two(n,k,p);
    long long q_n, r_n, q_k, r_k, choose;
    q_n = n / p;
    r_n = n % p;
    q_k = k / p;
    r_k = k % p;
    choose = choose_mod_two(r_n, r_k, p);
    // If the exponent of p in choose(n,k) isn't determined to be 0
    // before the calculation gets serious, short-cut here:
    *//*

 if (choose == 0) return 0; *//*
*/
/*

    choose *= choose_mod_one(q_n, q_k, p);
    return choose % p;
}

int r[2000];

long long int get_comb(int n , int k){}

int main()
{
    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int N, M; scanf("%d %d", &N, &M);

        int sum = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &r[i]);
            sum += (r[i] << 1);
        }

        long long int ans = 0;
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
                ans += get_comb(M - 2 - sum + r[i] + r[j], N - 1);

        printf("Case #%d: %lld\n", tc, (ans << 1) % MOD);
    }
    return 0;
}
*/
