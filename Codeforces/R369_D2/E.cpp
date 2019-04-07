//
// Created by Acka on 8/29/16.
//

#include <stdio.h>

#define MOD 1000003

long long int get_gcd(int a, int b){
   return b ? get_gcd(b, a % b) : a;
}

int main()
{
   long long int a = 1, b = 1;
   for(int i = 0; i < 9; i++)
       a = (a * 16) % MOD;
   for(int i = 0; i < 9; i++)
       b = (b * 15) % MOD;

   long long int c = (b - a + MOD) % MOD;
   printf("%lld / %lld\n", c, a);

   long long int gcd = get_gcd(c, a);
   printf("%lld: %lld / %lld\n", gcd, c / gcd, a / gcd);

   return 0;
}